#include "CSVFileUtil.h"

CSVRow::CSVRow(){}

CSVRow::CSVRow(std::string oriStr):m_data(split(oriStr, ",")){}

CSVRow::CSVRow(std::vector<std::string> oriVector):m_data(oriVector){}

std::string const& CSVRow::operator[](std::size_t index) const{
    return m_data[index];
}
std::size_t CSVRow::size() const{
    return m_data.size();
}
void CSVRow::readNextRow(std::istream& str){
    std::string         line;
    std::getline(str, line);

    std::stringstream   lineStream(line);
    std::string         cell;

    m_data.clear();
    while(std::getline(lineStream, cell, ',')){
        m_data.push_back(cell);
    }
}
void CSVRow::writeIntoStr(std::ostream& str){
    for(size_t i = 0; i < this->m_data.size()-1; i++){
        std::string cell(this->m_data[i]);
        str << cell << ",";
    }
    if(this->size() != 0)
        str << this->m_data[this->size()-1];
    }

std::istream& operator>>(std::istream& str, CSVRow& data){
    data.readNextRow(str);
    return str;
}

std::ostream& operator<<(std::ostream& str, CSVRow& data){
    data.writeIntoStr(str);
    return str;
}



CSVIterator::CSVIterator(std::istream& str)  :m_str(str.good()?&str:NULL) { ++(*this); }
CSVIterator::CSVIterator()                   :m_str(NULL) {}

// Pre Increment
CSVIterator& CSVIterator::operator++(){
    if (m_str) {
        (*m_str) >> m_row;
        m_str = m_str->good() ? m_str : NULL;
    }
    return *this;
}
// Post increment
CSVIterator CSVIterator::operator++(int) {
    CSVIterator tmp(*this);
    ++(*this);
    return tmp;
}
CSVRow const& CSVIterator::operator*() const {
    return m_row;
}
CSVRow const* CSVIterator::operator->() const {
    return &m_row;
}

bool CSVIterator::operator==(CSVIterator const& rhs) {
    return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL)));
}
bool CSVIterator::operator!=(CSVIterator const& rhs) {
    return !((*this) == rhs);
}

