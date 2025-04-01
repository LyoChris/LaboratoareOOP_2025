#pragma once

#include <iostream>

class JsonValue{
public:
	virtual ~JsonValue() = 0;

	virtual void print(std::ostream& out) = 0;
	virtual operator unsigned() const = 0;
};


class NullValue : public JsonValue {
private:
	double value;
public:
	~NullValue() override;
	void print(std::ostream& out) override;
	operator unsigned() const override;
};

class NumberValue : public JsonValue {
	double value;
public:
	NumberValue(double val) : value(val) {}
	~NumberValue() override;
	void print(std::ostream& out) override;
	operator unsigned() const override;
};

class BoolValue : public JsonValue {
	bool value;
public:
	explicit BoolValue(bool val);
	~BoolValue() override;
	void print(std::ostream& out) override;
	operator unsigned() const override;
};

class StringValue : public JsonValue {
	char value[256];
public:
	explicit StringValue(const char* val);
	~StringValue() override;
	void print(std::ostream& out) override;
	operator unsigned() const override;
};

class ArrayValue : public JsonValue {
	JsonValue* values[16];
	unsigned count = 0;
public:
	ArrayValue();
	~ArrayValue() override;
	void add(JsonValue* val);
	void print(std::ostream& out) override;
	operator unsigned() const override;
};

class ObjectValue : public JsonValue {
	struct Pair {
		char name[256];
		JsonValue* value;
	};
	Pair pairs[16];
	unsigned count = 0;
public:
	ObjectValue();
	~ObjectValue() override;
	void add(const char* name, JsonValue* val);
	void print(std::ostream& out) override;
	operator unsigned() const override;
};