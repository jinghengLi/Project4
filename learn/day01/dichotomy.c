//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{	
//	int arr[] = { 1, 2, 3, 4, 5, 6, 9, 10, 14, 19 };
//	int target = 10;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	for (; left <= right;)  //»òÕßwhile(left <= right)
//	{
//		int mid = (left + right) / 2;    //int mid = left + (right - left) / 2; //·ÀÖ¹Òç³ö
//			if (arr[mid] < target)
//			{
//				left = mid + 1;
//			}
//			else if (arr[mid] > target)
//			{
//				right = mid - 1;
//			}
//			else
//			{
//				printf("Found %d at index %d\n", target, mid);
//				break;
//			}
//	}
//	if (left > right)
//		printf("Target %d not found in the array.\n", target);
//
//	return 0;
//}