#ifndef TEST_CONVERSION_RULE_HPP
#define TEST_CONVERSION_RULE_HPP

#include "asset_pipeline/discovery/conversion_rule.hpp"

BW_BEGIN_NAMESPACE

class TestConversionRule : public ConversionRule
{
  public:
    /* returns true and populates a conversion task if the rule can match the
     * input filename. */
    virtual bool createTask(const BW::StringRef& sourceFile,
                            ConversionTask&      task);

    /* returns true if the rule can match the output filename. */
    virtual bool getSourceFile(const BW::StringRef& file,
                               BW::string&          sourcefile) const;
};

BW_END_NAMESPACE

#endif // TEST_CONVERSION_RULE_HPP
