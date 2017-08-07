#include "jsonparser.h"

////////////////////////////
/// \brief JsonNumber::JsonNumber
////////////////////////////
JsonNumber::JsonNumber(){
    type = JSON_NUMBER;
    valueNumber = 0;
}

JsonNumber::JsonNumber(double num){
    type = JSON_NUMBER;
    valueNumber = num;
}

std::string JsonNumber::getString(){
    return std::to_string(valueNumber);
}

double JsonNumber::getNumber(){
    return valueNumber;
}

/////////////////////////////////
///// \brief JsonBool::JsonBool
/////////////////////////////////
JsonBool::JsonBool(){
    type = JSON_BOOL;
    valueBool = true;
}

JsonBool::JsonBool(bool value){
    type = JSON_BOOL;
    valueBool = value;
}

std::string JsonBool::getString(){
    return valueBool? "true" : "false";
}

bool JsonBool::getBool(){
    return valueBool;
}



///////////////////////////////////
///// \brief JsonString::JsonString
///////////////////////////////////
JsonString::JsonString(){
    type = JSON_STRING;
    valueString = "";
}

JsonString::JsonString(std::string value){
    type = JSON_STRING;
    valueString = value;
}

std::string JsonString::getString(){
    return valueString;
}


////////////////////////////////////
///// \brief JsonArray::JsonArray
////////////////////////////////////
JsonArray::JsonArray(){
    type = JSON_ARRAY;
}

JsonArray::JsonArray(std::vector<JsonValue*> value){
    type = JSON_ARRAY;
    array = value;
}

std::string JsonArray::getString(){
    std::string ans = "[";
    if(array.size() == 0) return ans + "]";
    for(auto item: array){
        ans = ans + item->getString();
        ans = ans + ",";
    }
    ans = ans.substr(0, ans.length() - 1);
    ans = ans + "]";
    return ans;
}

std::vector<JsonValue*> JsonArray::getArray(){
    return array;
}

void JsonArray::append(JsonValue* value){
    array.push_back(value);
}

JsonValue* JsonArray::pop(){
    JsonValue *t = array.back();
    array.pop_back();
    return t;
}


///////////////////////////////////////////
///// \brief JsonObject::JsonObject
///////////////////////////////////////////
JsonObject::JsonObject(){
    type = JSON_OBJECT;
}

JsonObject::JsonObject(std::map<JsonValue *, JsonValue *> value){
    type = JSON_OBJECT;
    object = value;
}

JsonObject::JsonObject(JsonValue *first, JsonValue *second){
    type = JSON_OBJECT;
    append(first, second);
}

std::string JsonObject::getString(){
    if(object.size() == 0) return "{}";
    std::string ans = "{";
    std::map<JsonValue*, JsonValue*>::iterator it = object.begin();
    while(it != object.end()){
        ans = ans + it->first->getString();
        ans = ans + ":";
        ans = ans + it->second->getString();
        ans = ans + ",";
        ++it;
    }
    ans = ans.substr(0, ans.length() - 1);
    ans = ans + "}";
    return ans;
}

std::map<JsonValue*, JsonValue*> JsonObject::getObject(){
    return object;
}

void JsonObject::append(JsonValue *first, JsonValue *second){
    object.insert(std::make_pair(first, second));
}

JsonValue* JsonObject::getValue(JsonValue *key){
    std::map<JsonValue*, JsonValue*>::iterator iter = object.find(key);
    if(iter != object.end()){
        return iter->second;
    }
    return nullptr;
}







