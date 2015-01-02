#define BUILDING_NODE_EXTENSION
#include <string>
#include <list>
#include <map>
#include <node.h>
//#include "lophilo.h"

using namespace v8;
using namespace std;

#define DEFINE_FUNCTION_HANDLE(fun_name) \
Handle<Value> fun_name##_agent(const Arguments& args) {return agent(#fun_name, args);}
#define GET_FUNCTION_HANDLE(fun_name) \
fun_name##_agent
#define DEFINE_FUNCTION(ret,function,arg) \
    {#ret,#function,arg, (void*)function, GET_FUNCTION_HANDLE(function)},

#define REGISTER int
#define MAX_ARGC 8
#define ARG(x) (arg[x])
#define ARG0
#define ARG1 ARG(0)
#define ARG2 ARG1, ARG(1)
#define ARG3 ARG2, ARG(2)
#define ARG4 ARG3, ARG(3)
#define ARG5 ARG4, ARG(4)
#define ARG6 ARG5, ARG(5)
#define ARG7 ARG6, ARG(6)
#define ARG8 ARG7, ARG(7)
typedef int (*FUNC0)(void);
typedef int (*FUNC1)(REGISTER);
typedef int (*FUNC2)(REGISTER,REGISTER);
typedef int (*FUNC3)(REGISTER,REGISTER,REGISTER);
typedef int (*FUNC4)(REGISTER,REGISTER,REGISTER,REGISTER);
typedef int (*FUNC5)(REGISTER,REGISTER,REGISTER,REGISTER,
                     REGISTER);
typedef int (*FUNC6)(REGISTER,REGISTER,REGISTER,REGISTER,
                     REGISTER,REGISTER);
typedef int (*FUNC7)(REGISTER,REGISTER,REGISTER,REGISTER,
                     REGISTER,REGISTER,REGISTER);
typedef int (*FUNC8)(REGISTER,REGISTER,REGISTER,REGISTER,
                     REGISTER,REGISTER,REGISTER,REGISTER);

Handle<Value> agent(string name, const Arguments& args) 
{
  HandleScope scope;
  if (name == "led") {
    void* func_address;
    int   func_arg;
    ulong argc = 10;
    REGISTER ret;
    REGISTER arg[MAX_ARGC];
//    func_address = get_func_address(name);
//    func_arg     = (int)get_func_argc_by_name(name);
        switch(argc) {
            case 0: ret = ((FUNC0)func_address)(ARG0); break;
            case 1: ret = ((FUNC1)func_address)(ARG1); break;
            case 2: ret = ((FUNC2)func_address)(ARG2); break;
            case 3: ret = ((FUNC3)func_address)(ARG3); break;
            case 4: ret = ((FUNC4)func_address)(ARG4); break;
            case 5: ret = ((FUNC5)func_address)(ARG5); break;
            case 6: ret = ((FUNC6)func_address)(ARG6); break;
            case 7: ret = ((FUNC7)func_address)(ARG7); break;
            case 8: ret = ((FUNC8)func_address)(ARG8); break;
            default: break;
        }
	  return scope.Close(Undefined());

  } else {

	  if (args.Length() < 2) {
	    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
	    return scope.Close(Undefined());
	  }

	  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
	    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
	    return scope.Close(Undefined());
	  }

	  Local<Number> num = Number::New(args[0]->NumberValue() +
	      args[1]->NumberValue());
	  return scope.Close(num);
  }
}

char add(char a,char b)
{

}

void led(char a,char b)
{

}

DEFINE_FUNCTION_HANDLE(add);
DEFINE_FUNCTION_HANDLE(led);

typedef struct table_t 
{
    string return_type;
    string name;
    string arg_list;
    void* addr;
    Handle<Value> (*call)(const Arguments&);
}fun_table;

fun_table TABLE_NULL = 
{"", "", "", NULL, NULL};

fun_table table[] =
{
DEFINE_FUNCTION(char,add,"char a, char b")
DEFINE_FUNCTION(void,led,"char a, char b")
TABLE_NULL
};
//todo map<string, void*> fun_table;

void Init(Handle<Object> exports) {
  int i = 0;
  fun_table* table_p = table;
  while(table_p != &TABLE_NULL) {
    exports->Set(String::NewSymbol(table_p->name.c_str()),
        FunctionTemplate::New(table_p->call)->GetFunction());
    table_p++;
  }
}

NODE_MODULE(meteroi, Init)
