<Query Kind="Program" />

void Main()
{
	int[] reading = new int[6] { 4, 9, 1, 0, 21, 12 };
	
	for(int i=0; i<reading.Length; ++i)
	{
		Console.WriteLine(reading[i]);
	}
	
	string data1 = "Andy";
	string data2 = "Dave";
	string data3 = "trump";
	string data4 = "Anthor";
	
	Console.WriteLine((int)data1[0]);
	Console.WriteLine(hash_func( (int)data1[0] ));
	
	storage_data("Andy", 12345);
	storage_data("Dave", 54321);
	storage_data("Trump", 98765);
	
	Console.WriteLine(get_data("ANdy"));
}

// Define other methods, classes and namespaces here
static int[] hash_table = new int[6];

int hash_func(int InKey)
{
	return InKey % 6;
}

void storage_data(string InData, int InValue)
{
	int key = (int)InData[0];
	int hash_address = hash_func(key);
	hash_table[hash_address] = InValue;
}

int get_data(string InData)
{
	int key = (int)InData[0];
	int hash_address = hash_func(key);
	return hash_table[hash_address];
}