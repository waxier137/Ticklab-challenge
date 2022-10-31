#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *datafld;
	datafld = fopen("data.txt", "r"); // mở file
	if (datafld == NULL)
	{
		printf("\n File is unable to open"); // nếu mở file không thành công, báo lỗi và exit
		exit(0);
	}
	char *data;
	data = (char *)malloc(1000 * sizeof(char)); // tạo mảng động kiểu char
	int res1 = 0;								// tạo biến đếm số lượng kí tự
	while (!feof(datafld))
	{
		fscanf(datafld, "%c", &(*(data + res1))); // lấy dữ liệu từ file
		res1++;
	}

	for (int x = 0; x < res1; x++)
	{
		printf("%c", *(data + x));
	}
	free(datafld);	 // free memory của mảng động
	fclose(datafld); // đóng file
	return (0);
}
