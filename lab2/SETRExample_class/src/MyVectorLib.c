#include <string.h> 		/* For memset */
#include <MyVectorLib.h>

static int MyVectorLib_Vect[MYVECTLIB_MAXLEN]; 	/* Vector */
static int MyVectLen=0;							/* Number of elements in the vector*/

/* Initializes the vector */
void MyVectorLib_Init(void){
	MyVectLen=0;
	memset(MyVectorLib_Vect,0,sizeof(MyVectorLib_Vect));
	return;
} 		

/* Adds an element to the vector */
int MyVectorLib_Add(int number){
	MyVectorLib_Vect[MyVectLen]=number; 	/* Missing something ? */
	MyVectLen++;							/* Increment length of the vector to add a new element*/
	return MYVECTLIB_OK;
}	

/* Returns the position of number (is it an index or ordinal?) */
int MyVectorLib_Find(int number)
{
    int i = 0;
        
    while (i < MyVectLen) {		
        if (MyVectorLib_Vect[i] == number)
			return (i);
		i++;
	}
	
    return MYVECTLIB_NOTFOUND;
}

/* Returns the number of elements in the vector */
int MyVectorLib_Len(void)
{
	return MyVectLen;
}

/* Removes one element from the vector */
void MyVectorLib_Delete(int number)
{
	int i = 0;

	while (i<MyVectLen)
	{
		if (MyVectorLib_Vect[i] == number)
		{
			int j = i;
			// While loop where the number is removed and all elemets go one spot forward
			while(j<MyVectLen-1)
			{
				MyVectorLib_Vect[j] = MyVectorLib_Vect[j+1];
				j++;
			}
			
			// Decrease the total length because of the number removed
			MyVectLen--;
		} 	
		else
		{
			// Only when the number it's not removed, that we can increment the index
			// If not we will skip the new number positon 
			i++;
		}
	}
}

/* Sorts the vector */ 
void MyVectorLib_Sort(void)
{
	int i = 0;
	int temp;

	while (i<MyVectLen-1)
	{
		int j = 1;
		while (j<MyVectLen-i)
		{
			if (MyVectorLib_Vect[i]>MyVectorLib_Vect[i+j])
			{
				temp = MyVectorLib_Vect[i];
				MyVectorLib_Vect[i] = MyVectorLib_Vect[i+j];
				MyVectorLib_Vect[i+j] = temp; 
			}
			j++;
		}
		i++;
	}
}

/* Returns the maximum value in the vector */
int MyVectorLib_Max(void)
{
	int i = 0;
	int temp = 0;

	while (i<MyVectLen)
	{
		if (MyVectorLib_Vect[i]>=temp)
		{
			temp = MyVectorLib_Vect[i];
		}
		i++;
	}
	return temp;
}

/* Returns the minimum value in the vector */
int MyVectorLib_Min(void)
{
	int i = 0;
	int temp = 10000;

	while (i<MyVectLen)
	{
		if (MyVectorLib_Vect[i]<=temp)
		{
			temp = MyVectorLib_Vect[i];
		}
		i++;
	}
	return temp;
}

/* Returns the average value of the vecotr */
int MyVectorLib_Avg(void)
{
	int i = 0;
	int sum = 0;

	while (i<MyVectLen)
	{
		sum += MyVectorLib_Vect[i];
		i++;
	}

	return sum/MyVectLen;
}
