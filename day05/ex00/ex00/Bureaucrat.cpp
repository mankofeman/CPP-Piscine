#include "Bureaucrat.hpp"

// Constructors, destructor

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int range) : _name(name), _range(range) {
	std::cout << name << " has the " << range << " range level" << std::endl;
	if (range < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (range > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }
Bureaucrat::~Bureaucrat() {}

// Getter, setter, overloads

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this == &other)
		return *this;
	this->_name = other.getName();
	this->_range = other.getRange();
	return *this;
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &other) {
	stream << other.getName();
	return stream;
}

const std::string &Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getRange() const { return this->_range; }

// Methods

void Bureaucrat::upGrade() {
	if (this->_range - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else {
		this->_range--;
		std::cout << _name << " range is level up! Range is " << _range << std::endl;
	}
};
void Bureaucrat::downGrade() {
	if (this->_range + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else {
		this->_range++;
		std::cout<< _name << " range is level down! Range is " << _range << std::endl;
	}
};

// ToHighGradeException

Bureaucrat::GradeTooHighException::GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &) throw() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException &grade) throw() {
	if (this == &grade)
		return *this;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high!"; }

// ToLowGradeException

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &) throw() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException &grade) throw() {
	if (this == &grade)
		return *this;
	return *this;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low!"; }