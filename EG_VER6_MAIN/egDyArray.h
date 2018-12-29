#if !defined(AFX_EGEDUCLASS_H__AB344624_2C78_408B_8367_FE89A3B6A6BE__INCLUDED_)
#define AFX_EGEDUCLASS_H__AB344624_2C78_408B_8367_FE89A3B6A6BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class egDyArray{
	private:
		int* m_array;
		int m_size;
		int m_used;
	public:
		egDyArray();
		egDyArray(int size);
		~egDyArray();
 
		void popBack();
		void pushBack(int data);
		void print();
		int &operator[](int index);
};

#endif // !defined(AFX_EDUGREENDLG_H__23B7ECB3_55A7_4575_9D81_3ED3BD1B9B91__INCLUDED_)