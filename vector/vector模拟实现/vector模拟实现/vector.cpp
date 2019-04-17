#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

template <class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	//���캯��
	Vector()
		:start(nullptr), finish(nullptr), endOfStorage(nullptr)
	{}

	//��������
	Vector(Vector<T>& v)
	{
		start = new T[v.Capacity()];
		for (size_t i = 0; i < v.Size(); i++)
		{
			start[i] = v[i];
		}
		finish = start + v.Size();
		endOfStorage = start + v.Capacity();
	}

	//��������
	~Vector()
	{
		if (start)
		{
			delete[]start;
			start = finish = endOfStorage = nullptr;
		}
	}

	//������
	iterator Begin()
	{
		return start;
	}
	iterator End()
	{
		return finish;
	}
	const_iterator Begin() const
	{
		return start;
	}
	const_iterator End() const
	{
		return finish;
	}

	//��ȡ���ݸ���
	size_t Size()const
	{
		return finish - start;
	}

	//��ȡ������С
	size_t Capacity()const
	{
		return endOfStorage - start;
	}

	//�ж��Ƿ�Ϊ��
	bool Empty()
	{
		return finish == start;
	}

	//β��
	void PushBack(size_t val)
	{
		if (finish == endOfStorage)
		{
			size_t newcap = (start == nullptr ? 1 : 2 * Capacity());
			Reserve(newcap);
		}
		*finish= val;
		++finish;
	}

	//βɾ
	void PopBack()
	{
		Erase(finish - 1);
	}

	//[]���أ�������һ������
	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return start[pos];
	}

	const T& operator[](size_t pos)const
	{
		assert(pos < Size());
		return start[pos];
	}

	//��ֵ���������
	/*Vector <T>& operator = (Vector<T>& v)
	{
		if (this != &v)
		{
			T*temp = new T[v.Capacity()];
			if (start)
			{
				delete[]start;
			}
			start = temp;
			finish = start + v.Size();
			endOfStorage = start + v.Capacity();
		}
		return *this;
	}*/

	//��������vector���ݿռ�
	void Swap(Vector<T>&v)
	{
		swap(start, v.start);
		swap(finish, v.finish);
		swap(endOfStorage, v.endOfStorage);
	}

	//��ֵ���������
	Vector<T>& operator=(Vector<T>v)
	{
		Swap(v);
		return *this;
	}

	//ɾ��pos��Ӧλ������
	iterator Erase(iterator pos)
	{
		assert(pos < finish && pos>=start);
		iterator begin = pos + 1;
		while (begin < finish)
		{
			*(begin - 1) = *(begin);
			++begin; 
		}
		--finish;
		return pos;
	}

	//�ı�vector����capacity
	void Reserve(size_t n)
	{
		size_t len = Size();
		if (n > Capacity())
		{
			T* temp = new T[n];
			if (start)
			{
				for (size_t i = 0; i < len; i++)
				{
					temp[i] = start[i];
				}
				delete[]start;
			}
			start = temp;
			finish = start + len;
			endOfStorage = start + n;
		}
	}

	//�ı�vector��size
	void Resize(size_t n,const T &value=T())
	{
		if (n <= Size())
		{
			finish = start + n;
		}
		else
		{
			if (n > Capacity())
			{
				Reserve(n);
			}
			while (finish != start + n)
			{
				*finish = value;
				++finish;
			}
		}
	}

	//��posλ�ò���value
	void Insert(iterator pos, const T&value=T())
	{
		assert(pos <= finish&&pos >= start);
		size_t len = pos - start;
		if (finish == endOfStorage)
		{
			size_t newcap = start == nullptr ? 1 : 2 * Capacity();
			Reserve(newcap);
		}
		pos = start + len;
		iterator end = finish;
		while (end>pos)
		{
			*end = *(end - 1);
			--end;
		}
		*pos = value;
		++finish;
	}

private:
	T* start;
	T* finish;
	T* endOfStorage;
};

template <class T>
void PrintVector(const Vector<T>&v)
{
	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void test()
{
	Vector <int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	v.PushBack(7);
	PrintVector(v);
	v.PopBack();
	v.PopBack();
	PrintVector(v);
	Vector <int>v2(v);
	PrintVector(v2);
	Vector <int>v3;
	v3 = v;
	PrintVector(v3);
	v3.Erase(v3.Begin());
	PrintVector(v3);
	v3.Insert(v3.Begin() + 1, 100);
	PrintVector(v3);
}


int main()
{
	test();
	system("pause");
	return 0;
}
