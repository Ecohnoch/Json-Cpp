#include <iostream>
#include "jsonparser.h"

using namespace std;

int main(int argc, char *argv[])
{
    JsonObject me;
    JsonString *s1 = new JsonString("ddd");
    JsonNumber *s2 = new JsonNumber(2);
    JsonString *s3 = new JsonString("ccc");
    me.append(s1, s2);
    me.append(s3, s2);

    cout<<me.getString()<<endl;
    return 0;
}
