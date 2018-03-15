#include "Book.h"

Book::Book() : title("") {}

Book::Book(std::string s) : title(s) {}

void Book::set_title(std::string t) { title = t; }

std::string Book::get_title() { return title; }

void Book::set_startDate(Date s) { start_date = s; }

Date Book::get_startDate() { return start_date; }

void Book::set_lastPass(Date l) { last_pass = l; }

Date Book::get_lastPass() { return last_pass; }

void Book::set_endDate(Date e) { end_date = e; }

Date Book::get_endDate() { return end_date; }
