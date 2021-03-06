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
        CSVRow();

        CSVRow(std::string oriStr);

        CSVRow(std::vector<std::string> oriVector);

        std::string const& operator[](std::size_t index) const;
        std::size_t size() const;
        void readNextRow(std::istream& str);
        void writeIntoStr(std::ostream& str);
    private:
        std::vector<std::string>    m_data;
};

extern std::istream& operator>>(std::istream& str, CSVRow& data);

extern std::ostream& operator<<(std::ostream& str, CSVRow& data);


class CSVIterator
{
    public:
        typedef std::input_iterator_tag     iterator_category;
        typedef CSVRow                      value_type;
        typedef std::size_t                 difference_type;
        typedef CSVRow*                     pointer;
        typedef CSVRow&                     reference;

        CSVIterator(std::istream& str);
        CSVIterator();

        // Pre Increment
        CSVIterator& operator++();
        // Post increment
        CSVIterator operator++(int);
        CSVRow const& operator*() const;
        CSVRow const* operator->() const;

        bool operator==(CSVIterator const& rhs);
        bool operator!=(CSVIterator const& rhs);
    private:
        std::istream*       m_str;
        CSVRow              m_row;
};

#endif // CSVFILEUTIL_H_INCLUDED
