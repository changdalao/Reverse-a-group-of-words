#include<stdio.h>
#include<assert.h>
#define __DEBUG__ 0

int my_strlen(char *p);
void reverse(char arr[], int left, int right);
char chack(char *arr, int sz);

int main()
{
	char arr[] = "student a am i";
	int sz = my_strlen(arr);
	chack(arr, sz);  //����
	printf("%s\n", arr);
	return 0;
}

int my_strlen(char *p)
{
	int count = 0;
	assert(p != NULL);	//�ж�����ָ���Ƿ�Ϊ��
	while ((*p) != '\0')
	{
		count++;
		p++;
	}
	return count;
}
void reverse(char arr[], int left, int right)//�����ʵ��
{
	while (left<right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
#if __DEBUG__
	printf("%s", arr); //�۲������Ƿ�ɹ�
	printf("\n");
#endif //__DEBUG__
}
char chack(char *arr, int sz)
{
	int i = 0;
	int left = 0;
	int right = sz - 1;
	reverse(arr, left, right);  //���������ַ���
	while (arr[i] != '\0')
	{
		//���򵥴�
		left = i;
		while (arr[i] != ' '&&arr[i] != '\0')
		{
			i++;
		}
		right = i - 1;
		reverse(arr, left, right);
		if (arr[i] == ' ')
			i++;
	}
	return arr;
}