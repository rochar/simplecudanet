
int elementsCount = 10000;

var vector1 = Enumerable.Range(0,elementsCount).ToArray();
var vector2 = Enumerable.Range(0, elementsCount).ToArray();

var result = AddVectorsKernel.AddVectors(vector1, vector2,elementsCount);

Console.WriteLine($"result.Length={result.Length}, result[10]={result[10]}");
