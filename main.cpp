#include <iostream>
#include <string>
#include <node.h> //

using namespace std;
using namespace v8; // Add the missing namespace for v8

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Number;
using v8::Value;

namespace main {
    string HelloWorld() {
        return "hola mundo";
    }

    void method(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        string result = HelloWorld();
        Local<String> returnValue = String::NewFromUtf8(isolate, result.c_str()).ToLocalChecked();
        args.GetReturnValue().Set(returnValue);
    }


    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "helloWorld", method);// Implementation of Initialize function
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
}
