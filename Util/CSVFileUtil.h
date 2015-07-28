#ifndef CSVFILEUTIL_H_INCLUDED
#define CSVFILEUTIL_H_INCLUDED
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <string>
#include "DataFormatUtil.h"
class CSVRow{
    public:
        CSVRow(){}

        CSVRow(std::string oriStr):m_data(split(oriStr, ",")){}

        CSVRow(std::vector<std::string> oriVector):m_data(oriVector){}

        std::string const& operator[](std::size_t index) const{
            return m_data[index];
        }
        std::size_t size() const{
            return m_data.size();
        }
        void readNextRow(std::istream& str){
            std::string         line;
            std::getline(str, line);

            std::stringstream   lineStream(line);
            std::string         cell;

            m_data.clear();
            while(std::getline(lineStream, cell, ',')){
                m_data.push_back(cell);
            }
        }
        void writeIntoStr(std::ostream& str){
            for(size_t i = 0; i < this->m_data.size()-1; i++){
                std::string cell(this->m_data[i]);
                str << cell << ",";
            }
            if(this->size() != 0)
                str << this->m_data[this->size()-1];
        }
    private:
        std::vector<std::string>    m_data;
};

std::istream& operator>>(std::istream& str, CSVRow& data){
    data.readNextRow(str);
    return str;
}

std::ostream& operator<<(std::ostream& str, CSVRow& data){
    data.writeIntoStr(str);
    return str;
}


class CSVIterator
{
    public:
        typedef std::input_iterator_tag     iterator_category;
        typedef CSVRow                      value_type;
        typedef std::size_t                 difference_type;
        typedef CSVRow*                     pointer;
        typedef CSVRow&                     reference;

        CSVIterator(std::istream& str)  :m_str(str.good()?&str:NULL) { ++(*this); }
        CSVIterator()                   :m_str(NULL) {}

        // Pre Increment
        CSVIterator& operator++(){
            if (m_str) {
                (*m_str) >> m_row;
                m_str = m_str->good() ? m_str : NULL;
            }
            return *this;
        }
        // Post increment
        CSVIterator operator++(int) {
            CSVIterator tmp(*this);
            ++(*this);
            return tmp;
        }
        CSVRow const& operator*() const {
            return m_row;
        }
        CSVRow const* operator->() const {
            return &m_row;
        }

        bool operator==(CSVIterator const& rhs) {
            return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL)));
        }
        bool operator!=(CSVIterator const& rhs) {
            return !((*this) == rhs);
        }
    private:
        std::istream*       m_str;
        CSVRow              m_row;
};

#endif // CSVFILEUTIL_H_INCLUDED
