/* Copyright (C) 2013-2016 David 'Mokon' Bond, All Rights Reserved */

#pragma once

#include <cereal/archives/json.hpp>
#include <cereal/access.hpp>
#include <cereal/types/polymorphic.hpp>
#include <string>

namespace mcommon {

using Id = std::string;

class Idable
{
  public:

    explicit Idable(const Id& i)
        : id(i)
    {  
    }

    Idable() = delete;

    virtual ~Idable() = default;

    Idable(const Idable&) = default;

    Idable& operator=(const Idable&) = default;

    Idable(Idable&&) = default;

    Idable& operator=(Idable&&) = default;

    const Id getId() const
    {
        return id;
    }

  private:

    Id id;
    
    template<class Archive> void serialize(Archive& archive)
    {
        archive(cereal::make_nvp("id", id));
    }

    template<class Archive> static void load_and_construct(Archive& ar,
                                                           cereal::construct<mcommon::Idable>& construct)
    {
        mcommon::Id id;
        ar(id);
        construct(id);
    }

    friend class cereal::access;

};

}
