<Query Kind="Program" />

void Main()
{
	SaveData("Andy", 23456);
	SaveData("Trump", 12345);
	SaveData("Suzy", 09876);
	
	Console.WriteLine(GetValue("Andy"));
}

// Define other methods, classes and namespaces here
static int[] HashTable = new int[10];

int HashFunction(string InKey)
{
	return (int)(InKey[0]) % 10;
}

void SaveData(string InKey, int InValue)
{
	int HashAddress = HashFunction(InKey);
	HashTable[HashAddress] = InValue;
}

int GetValue(string InKey)
{
	int HashAddress = HashFunction(InKey);
	return HashTable[HashAddress];
}