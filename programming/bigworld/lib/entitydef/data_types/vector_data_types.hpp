#ifndef VECTOR_DATA_TYPES_HPP
#define VECTOR_DATA_TYPES_HPP

#include "entitydef/data_type.hpp"

BW_BEGIN_NAMESPACE

template <typename TYPE>
class SimpleStreamElement;

/**
 *	This template class is used to represent the different types of vector data
 *	type.
 *
 *	@ingroup entity
 */
template <class VECTOR>
class VectorDataType : public DataType
{
    typedef SimpleStreamElement<VECTOR> VectorStreamElementT;

  public:
    VectorDataType(MetaDataType* pMeta);

  protected:
    virtual bool isSameType(ScriptObject pValue);

    virtual void setDefaultValue(DataSectionPtr pSection);

    virtual bool getDefaultValue(DataSink& output) const;

    virtual int streamSize() const;

    virtual bool addToSection(DataSource&    source,
                              DataSectionPtr pSection) const;

    virtual bool createFromSection(DataSectionPtr pSection,
                                   DataSink&      sink) const;

    virtual bool fromStreamToSection(BinaryIStream& stream,
                                     DataSectionPtr pSection,
                                     bool           isPersistentOnly) const;

    virtual void addToMD5(MD5& md5) const;

    virtual StreamElementPtr getStreamElement(size_t  index,
                                              size_t& size,
                                              bool&   isNone,
                                              bool    isPersistentOnly) const;

    virtual bool operator<(const DataType& other) const;

  private:
    static const int NUM_ELEMENTS;

    VECTOR defaultValue_;
};

BW_END_NAMESPACE

#endif // VECTOR_DATA_TYPES_HPP
