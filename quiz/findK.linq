<Query Kind="Program" />

void Main()
{
	var array = new int[] { 1, 5, 2, 6, 3, 7, 4 };
	var commands = new int[,] { { 2, 5, 3 },
							{ 4, 4, 1 },
							{ 1, 7, 3 } };
	
	/*
	int[] list = GetK(array, commands);
	if(list != null)
	{
		list.Length.Dump();
		list.Dump();
	}
	*/
	int[] result = solution(array, commands);
	for(int i=0; i<result.Length; i++)
	{
		Console.WriteLine("[{0:d}] -> {1:d}", i+1, result[i]);
	}
	
}

// Define other methods, classes and namespaces here
public int[] solution(int[] array, int[,] commands)
{
	int[] result = new int[commands.Length/3];
	for(int index=0; index<commands.Length/3; index++)
	{
		var i = commands[index, 0] - 1;
		var j = commands[index, 1] - 1;
		var k = commands[index, 2] - 1;
		
		var newLength = j-i+1;
		var newArray = new int[newLength];
		Array.Copy(array, i, newArray, 0, newLength);
		Array.Sort(newArray);
		
		result[index] = newArray[k];
	}
	
	return result;
}

int[] GetK(int[] array, int[,] commands)
{
	// error체크
	if (array.Length >= 100) return null;
	for (int i = 0; i < array.Length; ++i)
	{
		if (array[i] >= 100) return null;
	}
	var count = commands.Length / 3;
	if(count >= 50)	return null;
	if(commands.Length > count * 3) return null;
	
	int[] result = new int[count];
	for(int i=0; i<count; ++i)
	{
		var begin = commands[i, 0]-1;
		var end = commands[i, 1]-1;
		var position = commands[i, 2]-1;
		
		var size = end-begin+1;
		int[] list = new int[size];
		for(int j=0; j<size; ++j)
		{
			list[j] = array[begin+j]; 
		}
		//list.Dump();
		
		for(int k=0;k<size-1; ++k)
		{
			for(int l=k+1;l<size;++l)
			{
				if(list[k] > list[l])
				{
					var temp = list[k];
					list[k] = list[l];
					list[l] = temp;
				}
			}
		}		
		//list.Dump();
		
		result[i] = list[position];
	}
	
	//result.Dump();
	return result;
}