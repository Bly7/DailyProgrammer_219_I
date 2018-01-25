// Includes
// 
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{	
	// Set up output file
	std::ofstream outfile;
	outfile.open("output.txt");
	
	// Construct starting numbers
	int Snum = 100000;
	int Inum = 10;
	int SRnum = 0;
	int IRnum = 0;
	
	// Construct change rates
	float SIrate = 0.01f;
	float IRrate = 0.01f;
	float SRrate = 0.015f;
	
	// Get ARGV if given
	if (argc == 6)
	{
		Snum = std::stoi(argv[1]);
		Inum = std::stoi(argv[2]);
		SIrate = std::stof(argv[3]);
		IRrate = std::stof(argv[4]);
		SRrate = std::stof(argv[5]);
	}
	
	// Output Initial State	
	
	// To console
	std::cout << "Initial State\n---------------------------------" << std::endl;
	std::cout << "S: " << Snum << ", I: " << Inum << ", SR: " << SRnum << ", IR: " << IRnum << std::endl;
	std::cout << "SIrate: " << SIrate << ", IRrate: " << IRrate << ", SRrate: " << SRrate << std::endl;
	std::cout << "---------------------------------\nSIR Sim Start\n---------------------------------" << std::endl;
		
	// To file
	outfile << "Initial State\n---------------------------------\n";
	outfile << "S: " << Snum << ", I: " << Inum << ", SR: " << SRnum << ", IR: " << IRnum << "\n";
	outfile << "SIrate: " << SIrate << ", IRrate: " << IRrate << ", SRrate: " << SRrate << "\n";
	outfile << "---------------------------------\nSIR Sim Start\n---------------------------------\n";
	
	while (Snum > 0 || Inum > 0)
	{	
		// Handle the reductions
		
		// S -> R
		float SRchange = float(Snum) * SRrate;
		if (SRchange < 1 && SRchange > 0)
			SRchange = 1;
		Snum -= SRchange;
		
		// I -> R
		float IRchange = float(Inum) * IRrate;
		if (IRchange < 1 && IRchange > 0)
			IRchange = 1;
		Inum -= IRchange;
		
		// S -> I
		float SIchange = float(Snum) * SIrate;
		if (SIchange < 1 && SIchange > 0)
			SIchange = 1;
		Snum -= SIchange;
		
		// Handle Additions
		SRnum += SRchange;
		IRnum += IRchange;
		Inum += SIchange;
		
		// Output State Changes	
		
		// To console
		std::cout << "S: " << Snum << ", I: " << Inum << ", SR: " << SRnum << ", IR: " << IRnum << std::endl;
		
		// To file
		outfile << "S: " << Snum << ", I: " << Inum << ", SR: " << SRnum << ", IR: " << IRnum << "\n";
	}
	
	// Output results
	
	// To console
	std::cout << "---------------------------------\nFinal State\n---------------------------------" << std::endl;
	std::cout << "Snum: " << Snum << std::endl;
	std::cout << "Inum: " << Inum << std::endl;
	std::cout << "SRnum: " << SRnum << std::endl;
	std::cout << "IRnum: " << IRnum << std::endl;
	
	// To file
	outfile << "---------------------------------\nFinal State\n---------------------------------\n";
	outfile << "Snum: " << Snum << "\n";
	outfile << "Inum: " << Inum << "\n";
	outfile << "SRnum: " << SRnum << "\n";
	outfile << "IRnum: " << IRnum << "\n";
	
	// Close and save output file
	outfile.close();
	
	return 0;
}