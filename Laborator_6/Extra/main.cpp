#include "Json.h"
#include <fstream>

int main() {
    ObjectValue obj;
    obj.add("name", new StringValue("John Doe"));
    obj.add("age", new NumberValue(30));
    obj.add("is_student", new BoolValue(false));

    ArrayValue* hobbies = new ArrayValue();
    hobbies->add(new StringValue("reading"));
    hobbies->add(new StringValue("hiking"));
    hobbies->add(new NullValue());
    obj.add("hobbies", hobbies);

    ObjectValue* address = new ObjectValue();
    address->add("street", new StringValue("123 Main St"));
    address->add("city", new StringValue("Anytown"));
    obj.add("address", address);

    obj.print(std::cout);
    std::cout << "\n";


    std::ofstream outFile("output.json");
    if (outFile) {
        obj.print(outFile);
        outFile.close();
    }

    std::cout << "Total nodes in JSON structure: " << static_cast<unsigned>(obj) << "\n";

    return 0;
}