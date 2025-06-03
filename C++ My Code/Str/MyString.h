#pragma once
class MyString
{
	static int count;
	char* ptr;
public:
	MyString(const char* ptr = nullptr);
	MyString(const MyString& source);
	MyString(MyString&& source) noexcept;
	~MyString();
	MyString& operator=(const MyString& rhs);
	MyString& operator=(MyString&& rhs);
	MyString operator-() const;
	MyString operator+(const MyString& rhs) const;
	bool operator==(const MyString& rhs) const;
	void display() const;
	int get_len() const;
	const char* get_str() const;
};