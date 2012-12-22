/***
Copyright 2012 Devsim LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***/

#ifndef POW_HH
#define POW_HH
#include "EquationObject.hh"
namespace Eqo {
class Pow : public EquationObject {
    public:
        Pow(EqObjPtr, EqObjPtr);

        EqObjPtr Derivative(EqObjPtr);
        EqObjPtr Simplify();

        EqObjPtr CombineProduct(std::vector<EqObjPtr>);
        EqObjPtr CombineAdd(std::vector<EqObjPtr>);

        bool isZero();
        bool isOne();

        EqObjPtr getScale();
        EqObjPtr getUnscaledValue();

        double getSign();
        EqObjPtr getUnsignedValue();

        EqObjPtr clone();
        EqObjPtr subst(const std::string &, EqObjPtr);

        EqObjPtr expand();

        bool hasReciprocal() {return false;}
        EqObjPtr getReciprocal() {assert(false); return con(0);}
        std::set<std::string> getReferencedType(Eqo::EqObjType rt)
        {
            return UniteReferencedType(rt, base, exponent);
        }

        friend class Log;
        friend class Product;

        std::vector<EqObjPtr> getArgs() {
          return createArgs(base, exponent);
        }
    private:
        std::string createStringValue();

        Pow(const Pow &);
        Pow operator=(const Pow &);

        const EqObjPtr base;
        const EqObjPtr exponent;
};

}
#endif
