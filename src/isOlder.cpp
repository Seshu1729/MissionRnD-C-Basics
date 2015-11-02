/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isLeap(int year)
{
	int leap=1;
	if(year%4!=0)
		leap=0;
	else if(year%400==0)
		leap=1;
	else if(year%100==0)
		leap=0;
	return leap;
}

int isValid(int *date)
{
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(isLeap(date[2]))
		days[1]++;
	if(days[date[1]-1]<date[0]||date[0]<1)
		return 0;
	if(date[1]>12||date[1]<0)
		return 0;
	return 1;
}

void dateToNumber(char *dob,int *date)
{
	int index = 0;
	while(*dob)
	{
		while(*dob!='-'&&*dob)
			date[index] = (date[index]*10)+(*dob++)-48;
		index++;
	}
}

int isOlder(char *dob1, char *dob2) 
{
	int date1[3] = {0,0,0},date2[3] = {0,0,0},index = 2;
	dateToNumber(dob1,date1);
	dateToNumber(dob2,date2);
	if(!(isValid(date1)&&isValid(date2)))
		return -1;
	do
	{
		if(date1[index]>date2[index])
			return 1;
		else if(date1[index]<date2[index])
			return 2;
	}while(!(date1[index]-date2[index])&&index>=0);
	return 0;
}
