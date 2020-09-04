#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int Getmid(vector<int>& v, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (v[begin] < v[mid])
	{
		if (v[mid] < v[end])
			return mid;
		else if (v[begin] > v[end])
			return begin;
		else
			return end;
	}
	else
	{
		if (v[mid] > v[end])
			return mid;
		else if (v[begin] < v[end])
			return begin;
		else
			return end;
	}
}

int partsort1(vector<int>& v,int begin, int end)
{
	int mid = Getmid(v, begin, end);
	swap(v[mid], v[begin]);
	int key = v[begin];
	while (begin < end)
	{
		while (v[end] > key && begin < end)
			--end;
		v[begin] = v[end];
		while (v[begin] < key && begin < end)
			++begin;
		v[end] = v[begin];
	}
	v[begin] = key;
	return begin;
}	// �ڿӷ�

int partsort2(vector<int>& v, int begin, int end)
{
	int mid = Getmid(v, begin, end);
	swap(v[mid], v[end]);
	int prev = begin - 1;
	int cur = begin;
	int key = end;
	while (cur < end)
	{
		if (v[cur] < v[key] && ++prev != cur)
			swap(v[prev], v[cur]);
		++cur;
	}
	swap(v[++prev], v[key]);
	return prev;
}	// ǰ��ָ�뷨

void QuickSort(vector<int>& v, int begin, int end)
{
	if (begin >= end)
		return;
	int keyindex = partsort2(v, begin, end);
	QuickSort(v, begin, keyindex - 1);
	QuickSort(v, keyindex + 1, end);
}	// ���ŵݹ�汾


void QuickSortNonR(vector<int>& v, int begin, int end)
{
	stack<int>st;
	st.push(begin);
	st.push(end);
	while (!st.empty())
	{
		int right = st.top();
		st.pop();
		int left = st.top();
		st.pop();
		int keyindex = partsort2(v, left, right);
		if (left < keyindex - 1)
		{
			st.push(left);
			st.push(keyindex - 1);
		}
		if (keyindex + 1 < right)
		{
			st.push(keyindex + 1);
			st.push(right);
		}
	}
}	// ���ŷǵݹ�汾

void BubbleSort(vector<int>& v, int n)
{
	int end = n;
	int flag = 1;
	while (end > 0)
	{
		for (int i = 1; i < end; i++)
		{
			if (v[i - 1] > v[i])
			{
				swap(v[i - 1], v[i]);
				flag = 0;
			}
		}
		if (flag)
			break;
		--end;
	}
}	// ð������

void InsertSort(vector<int>& v, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = v[end + 1];
		while (end >= 0)
		{
			if (v[end] > tmp)
			{
				v[end + 1] = v[end];
				--end;
			}
			else
				break;
		}
		v[end + 1] = tmp;
	}
}	// ֱ�Ӳ�������


void ShellSort(vector<int>& v, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = v[end + gap];
			while (end >= 0)
			{
				if (v[end] > tmp)
				{
					v[end + gap] = v[end];
					end -= gap;
				}
				else
					break;
			}
			v[end + gap] = tmp;
		}
	}
}	// ϣ������

void _MergeSort(vector<int>& v, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_MergeSort(v, begin, mid, tmp);
	_MergeSort(v, mid + 1, end, tmp);
	int begin1 = begin, begin2 = mid + 1;
	int end1 = mid, end2 = end;
	int index = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (v[begin1] <= v[begin2])
			tmp[index++] = v[begin1++];
		else
			tmp[index++] = v[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = v[begin1++];
	while (begin2 <= end2)
		tmp[index++] = v[begin2++];
	for (begin1 = 0; begin1 < index; ++begin1)
		v[begin + begin1] = tmp[begin1];
}


void MergeSort(vector<int>& v, int n)
{
	int *tmp = new int[n];
	_MergeSort(v, 0, n - 1, tmp);
	delete[] tmp;
}
// =======================================================

void merge(int* a, int left, int mid, int right, int* tmp)
{
	// [left, mid]
	// [mid+1, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while(begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}


void mergePass(int *arr, int k, int n, int *temp)
{
	int i = 0;
	//��ǰ����,��2������Ϊk�������кϲ�Ϊ1��
	while (i < n - 2 * k + 1)
	{
		merge(arr, i, i + k - 1, i + 2 * k - 1, temp);
		i += 2 * k;
	}
	//�ϲ�����[i, n - 1]�������벿��[i, i + k - 1]�Լ�����һ���������Ұ벿��[i + k, n - 1]
	if (i < n - k)
	{
		merge(arr, i, i + k - 1, n - 1, temp);
	}
}

// �鲢����ǵݹ��
void MergeSortNonR(int *arr, int length)
{
	int k = 1;
	int *temp = (int *)malloc(sizeof(int)* length);
	while (k < length)
	{
		mergePass(arr, k, length, temp);
		k *= 2;
	}
	free(temp);
}



int main()
{
	vector<int> v = { 3, 5, 2, 1, 4, 6, 8, 7, -1, 0, 19, 35, 12 };

	// QuickSort(v, 0, v.size() - 1);
	// QuickSortNonR(v, 0, v.size() - 1);
	BubbleSort(v, v.size());
	// InsertSort(v, v.size());
	// ShellSort(v, v.size());
	// MergeSort(v, v.size());
	for (auto &e : v)
		cout << e << ' ';

	cout << endl;
	return 0;
}