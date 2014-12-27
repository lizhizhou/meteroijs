#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "lophilo.h"

using namespace v8;

Handle<Value> Add(const Arguments& args) {
  HandleScope scope;

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

Handle<Value> led_js(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 4) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()
		  || !args[2]->IsNumber() || !args[3]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }

  led(args[0]->NumberValue(), args[1]->NumberValue(), args[0]->NumberValue(),
		  args[3]->NumberValue());

  return scope.Close(Undefined());
}


void Init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("add"),
      FunctionTemplate::New(Add)->GetFunction());
  exports->Set(String::NewSymbol("led"),
      FunctionTemplate::New(led_js)->GetFunction());
}

NODE_MODULE(meteroi, Init)
