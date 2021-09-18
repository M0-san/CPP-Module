//
// Created by moboustt on 5/8/2021.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: Form(target, 137, 145), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->isIsSigned() && executor.getGrade() <= this->getGradeToExec())
	{
		std::fstream f;
		f.open(_target + "_shrubbery");
		if (f.good()){
			std::string tree = "    oxoxoo    ooxoo\n"
							   "  ooxoxo oo  oxoxooo\n"
							   " oooo xxoxoo ooo ooox\n"
							   " oxo o oxoxo  xoxxoxo\n"
							   "  oxo xooxoooo o ooo\n"
							   "    ooo\\oo\\  /o/o\n"
							   "        \\  \\/ /\n"
							   "         |   /\n"
							   "         |  |\n"
							   "         | D|\n"
							   "         |  |\n"
							   "         |  |\n"
							   "  ______/____\\____";
			f.write(tree.c_str(), tree.length());
		} else
			std::cout << "Cannot open the file: " << _target + "_shrubbery" << std::endl;
	} else
		throw GradeTooLowException ("Grade too low.");
}
