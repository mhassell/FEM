Finite elements for elliptic equations in 2D

TBD: 

	Because of the memory management by new-ing and delete-ing within the triangulation object, the "rule of three" indicates that I also need a copy constructor and a copy assignment operator for this class as well.  I don't think I'll need these in the code per se, but I will add them to learn these and mainatain best practices.

	Rename classes to be CClassName based, and adopt this henceforth

	Update test scripts

	Automate testing process (use shell)

	Decide on a standard version of g++ to use (g++11 seems natural...)

	Make make make all

	Once all tools are in place move to examples

	Implement proper regression tests and practices (learn them!)
		https://akrabat.com/the-beginners-guide-to-contributing-to-a-github-project/

