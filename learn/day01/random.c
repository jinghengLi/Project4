//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <time.h>
//void menu()
//{
//	printf("**********************************\n");
//	printf("************* 1. Start Game ************\n");
//	printf("************* 2. Exit Game ************\n");
//	printf("**********************************\n");
//}
//
//
//void game()
//{
//	int num = 0;
//	int guess = 0;
//	num = rand() % (100 - 1 + 1) + 1;
//	while (1)
//	{
//		printf("Please enter your guess (1-100): ");
//		scanf("%d", &guess);
//			if (guess > num)
//				printf("Your guess is too high!\n");
//			else if (guess < num)
//				printf("Your guess is too low!\n");
//			else
//			{
//			printf("Congratulations! You guessed the number %d correctly!\n", num);
//			break;
//			}
//	}
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//	while (1)                                     												
//	{                                                 
//		menu();                                   
//		int input = 0;                          
//		printf("Please enter your choice: ");               
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1:
//				game();
//				break;
//			case 2:
//				printf("Exiting the game. Goodbye!\n");
//				return 0;	
//			default:
//				printf("Invalid choice. Please try again.\n");
//				break;
//		}
//	}
//	return 0;
//}
//// 0~RAND_MAX (32767) 0~32767,所以对其取模%100，得到0~99，再加1，得到1~100的随机数
//// Seed the random number generator,不用每次都调用，只用在工程开始时调用一次，int *p = NULL 空指针为0
////srand()函数生成的随机数是伪随机数，使用时间作为种子，保证每次运行程序时生成的随机数不同												
////种子如果相同，则生成的随机数序列也相同，例如srand(1234); srand(1234);每次生成的随机数序列都相同
////srand(time(NULL))调用时间差太短，可能生成相同的随机数序列，因为time()函数的精度是秒
////多次调用srand(time(NULL))会导致生成的随机数序列相同，特别是在短时间内（同一秒）多次调用时
////所以在程序开始时调用一次srand(time(NULL))，然后调用rand()函数，这样程序会根据当前时间生成不同的随机数序列