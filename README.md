cpp_copyable_memo
========
コピー可能なオブジェクトと、コピー不可なオブジェクトの実装比較メモ。

<pre>
class Copyable {
public:
	Person();
	Person(const Person &obj);
	Person& operator=(const Person &obj) 
    ・
    ・
    ・
};

class NonCopyableClass1 {
public:
	NonCopyableClass1() {}

private:
	NonCopyableClass1(const NonCopyableClass1 &obj) {}
	NonCopyableClass1& operator=(const NonCopyableClass1 &obj) { return *this; }    ・
    ・
    ・
};
</pre>
