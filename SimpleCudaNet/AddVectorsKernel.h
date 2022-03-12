#pragma once
public ref class AddVectorsKernel abstract sealed
{
	public:
		static array<int>^ AddVectors(array<int>^ v1, array<int>^ v2, int elementsToAdd);
};
