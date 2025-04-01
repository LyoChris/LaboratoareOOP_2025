#include "Json.h"
#include <cstring>
#include <cstdio>

JsonValue::~JsonValue() = default;

NullValue::~NullValue() = default;

void NullValue::print(std::ostream& out) {
    out << "null";
}

NullValue::operator unsigned() const {
    return 1;
}

NumberValue::~NumberValue() = default;

void NumberValue::print(std::ostream& out) {
    out << value;
}

NumberValue::operator unsigned() const {
    return 1;
}

BoolValue::BoolValue(bool val) : value(val) {}

BoolValue::~BoolValue() = default;

void BoolValue::print(std::ostream& out) {
    out << (value ? "true" : "false");
}

BoolValue::operator unsigned() const {
    return 1;
}

StringValue::StringValue(const char* val) {
    if (val) {
        int len = strlen(val);
        if (len > 255) {
            len = 255;
        }
        strncpy(value, val, len);
        value[len] = '\0';
    }
    else {
        value[0] = '\0';
    }
}

StringValue::~StringValue() = default;

void StringValue::print(std::ostream& out) {
    out << "\"";
    for (const char* p = value; *p; ++p) {
        switch (*p) {
        case '"': out << "\\\""; break;
        case '\\': out << "\\\\"; break;
        case '\b': out << "\\b"; break;
        case '\f': out << "\\f"; break;
        case '\n': out << "\\n"; break;
        case '\r': out << "\\r"; break;
        case '\t': out << "\\t"; break;
        default: out << *p; break;
        }
    }
    out << "\"";
}

StringValue::operator unsigned() const {
    return 1;
}


ArrayValue::ArrayValue() {
    for (auto& val : values) {
        val = nullptr;
    }
}

ArrayValue::~ArrayValue() {
    for (unsigned i = 0; i < count; ++i) {
        delete values[i];
    }
}

void ArrayValue::add(JsonValue* val) {
    if (count >= 16) {
        return;
    }
    values[count++] = val;
}

void ArrayValue::print(std::ostream& out) {
    out << "[";
    for (unsigned i = 0; i < count; ++i) {
        if (i != 0) out << ", ";
        values[i]->print(out);
    }
    out << "]";
}

ArrayValue::operator unsigned() const {
    unsigned total = 1;
    for (unsigned i = 0; i < count; ++i) {
        total += static_cast<unsigned>(*values[i]);
    }
    return total;
}


ObjectValue::ObjectValue() {
    for (auto& pair : pairs) {
        pair.value = nullptr;
        pair.name[0] = '\0';
    }
}

ObjectValue::~ObjectValue() {
    for (unsigned i = 0; i < count; ++i) {
        delete pairs[i].value;
    }
}

void ObjectValue::add(const char* name, JsonValue* val) {
    if (count >= 16) {
        return;
    }
    if (name) {
        size_t len = strlen(name);
        if (len > 255) {
            len = 255;
        }
        strncpy(pairs[count].name, name, len);
        pairs[count].name[len] = '\0';
    }
    else {
        pairs[count].name[0] = '\0';
    }
    pairs[count].value = val;
    count++;
}

void ObjectValue::print(std::ostream& out) {
    out << "{";
    for (unsigned i = 0; i < count; ++i) {
        if (i != 0) out << ", ";
        StringValue name(pairs[i].name);
        name.print(out);
        out << ": ";
        pairs[i].value->print(out);
    }
    out << "}";
}

ObjectValue::operator unsigned() const {
    unsigned total = 1;
    for (unsigned i = 0; i < count; ++i) {
        total += static_cast<unsigned>(*pairs[i].value);
    }
    return total;
}
