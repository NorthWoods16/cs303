#include"Date.h"
#include<iostream>
#include "Library.h"

/*TODO
Create more tests*/

void main()
{
	Library library;
	library.addBook("Software Engineering");
	library.addBook("Chemistry");

	library.addEmployee("Adam");
	library.addEmployee("Sam");
	library.addEmployee("Ann");

	library.circulateBook("Chemistry", Date(2015, 3, 1, DateFormat::US));
	library.circulateBook("Software Engineering", Date(2015, 4, 1, DateFormat::US));

	library.pass_on("Chemistry", Date(2015, 3, 5, DateFormat::US));
	library.pass_on("Chemistry", Date(2015, 3, 7, DateFormat::US));
	library.pass_on("Chemistry", Date(2015, 3, 8, DateFormat::US));

	library.addBook("Sk8 Fast & Eat A$$");
	library.addBook("Dreams of Memes");

	library.circulateBook("Sk8 Fast & Eat A$$", Date(2015, 4, 15, DateFormat::US));
	library.circulateBook("Dreams of Memes", Date(2015, 5, 1, DateFormat::US));

	library.pass_on("Software Engineering", Date(2015, 4, 5, DateFormat::US));
	library.pass_on("Software Engineering", Date(2015, 4, 10, DateFormat::US));
	library.pass_on("Software Engineering", Date(2015, 4, 15, DateFormat::US));

	library.addEmployee("James");
	library.addEmployee("Sandy");
	library.addEmployee("Dinkleberg");

	Date passDate(2015, 4, 20, DateFormat::US);
	while (library.pass_on("Sk8 Fast & Eat A$$", passDate)) {
		passDate.add_days(3);
	}
	
	try {
		library.pass_on("Why Does my Mother Hit Me", Date(2015, 4, 20, DateFormat::US));
	}
	catch (invalid_argument e) {
		std::cout << "Error successfully caught";
	}
	system("pause");

}
