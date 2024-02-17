#ifndef GUI_FUNCTOR_DATASECTION_HPP__
#define GUI_FUNCTOR_DATASECTION_HPP__

#include "gui_functor.hpp"

BW_BEGIN_NAMESPACE
BEGIN_GUI_NAMESPACE

class DataSectionFunctor : public Functor
{
    DataSectionPtr ds_;

  public:
    void                      setRoot(DataSectionPtr root);
    virtual const BW::string& name() const;
    virtual bool              text(const BW::string& textor,
                                   ItemPtr           item,
                                   BW::string&       result);
    virtual bool              update(const BW::string& updater,
                                     ItemPtr           item,
                                     unsigned int&     result);
    virtual bool act(const BW::string& action, ItemPtr item, bool& result);
};

END_GUI_NAMESPACE
BW_END_NAMESPACE

#endif // GUI_FUNCTOR_OPTION_HPP__
