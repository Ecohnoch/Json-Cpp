// {
//     "data": 100,
//     "datas": [100, 200, 300, 400],
//     "allDatas":{
//         "data1": 100,
//         "data2": true,
//         "data3": null,
//         "data4": "dddd"
//     }
// }
//
#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <string>
#include <vector>
#include <map>

class JsonNumber;
class JsonBool;
class JsonString;
class JsonArray;
class JsonObject;
class JsonNull;

enum JSONTYPE{
    JSON_NUMBER,
    JSON_BOOL,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT,
    JSON_NULL
};

class JsonValue{
protected:
    JSONTYPE type;
    union{
        bool valueBool;
        double valueNumber;
        std::string valueString;
    };
public:
    JsonValue(){}
    ~JsonValue(){}
    virtual std::string getString(){}
    JSONTYPE getType(){ return type; }
};


class JsonNumber: public JsonValue{
public:
    JsonNumber();
    JsonNumber(double num);
    std::string getString();
    double getNumber();
};

class JsonBool: public JsonValue{
public:
    JsonBool();
    JsonBool(bool value);
    std::string getString();
    bool getBool();
};

class JsonString: public JsonValue{
public:
    JsonString();
    JsonString(std::string value);
    std::string getString();
};

class JsonArray: public JsonValue{
private:
    std::vector<JsonValue*> array;
public:
    JsonArray();
    JsonArray(std::vector<JsonValue*> value);
    std::string getString();
    std::vector<JsonValue*> getArray();
    void append(JsonValue* value);
    JsonValue* pop();
};

class JsonObject: public JsonValue{
private:
    std::map<JsonValue*, JsonValue*> object;
public:
    JsonObject();
    JsonObject(std::map<JsonValue*, JsonValue*> value);
    JsonObject(JsonValue* first, JsonValue* second);
    std::string getString();
    std::map<JsonValue*, JsonValue*> getObject();
    void append(JsonValue* first, JsonValue* second);
    JsonValue* getValue(JsonValue* key);
};

class JsonTokenizer{

};

class Json{
public:
    JsonNumber* parseNumber();
    JsonBool* parseBool();
    JsonString* parseString();
    JsonArray* parseArray();
    JsonObject* parseObject();
    JsonNull* parseNull();
private:
    JsonTokenizer tokenizer;
};



#endif // JSONPARSER_H
