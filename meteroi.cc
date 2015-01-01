#define BUILDING_NODE_EXTENSION
#include <string>
#include <node.h>
//#include "lophilo.h"

using namespace v8;
using namespace std;

#define DEFINE_FUNCTION_HANDLE(fun_name) \
Handle<Value> fun_name(const Arguments& args) {return agent(#fun_name, args);}

//ADD_FUNCTION_HANDLE(fun_name)
//{exports->Set(String::NewSymbol(#fun_name),FunctionTemplate::New(fun_name)->GetFunction());}

Handle<Value> agent(string function, const Arguments& args) {
  HandleScope scope;
  if (function == "led") {

	  if (args.Length() < 4) {
	    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
	    return scope.Close(Undefined());
	  }

	  if (!args[0]->IsNumber() || !args[1]->IsNumber()
			  || !args[2]->IsNumber() || !args[3]->IsNumber()) {
	    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
	    return scope.Close(Undefined());
	  }

	  //led(args[0]->NumberValue(), args[1]->NumberValue(), args[0]->NumberValue(),
	  //		  args[3]->NumberValue());

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

//Handle<Value> add(const Arguments& args) {
//  return agent("add",args);
//}
//
//Handle<Value> led(const Arguments& args) {
//  return agent("led",args);
//}

DEFINE_FUNCTION_HANDLE(add);
DEFINE_FUNCTION_HANDLE(led);

void Init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("add"),
      FunctionTemplate::New(add)->GetFunction());
  exports->Set(String::NewSymbol("led"),
      FunctionTemplate::New(led)->GetFunction());
}

NODE_MODULE(meteroi, Init)
