/* 
 * LSST Data Management System
 * * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
 * See the COPYRIGHT file
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the LSST License Statement and 
 * the GNU General Public License along with this program.  If not, 
 * see <https://www.lsstcorp.org/LegalNotices/>.
 */
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "lsst/meas/extensions/psfex/Field.hh"

#undef PI // defined by psfex, clashes with afw

#include "lsst/afw/image/Wcs.h"

namespace py = pybind11;
using namespace pybind11::literals;

namespace lsst {
namespace meas {
namespace extensions {
namespace psfex {

PYBIND11_PLUGIN(_field) {
    py::module mod("_field", "Python wrapper for the meas_extensions_psfex _field library");

    py::class_<Field, std::shared_ptr<Field>> clsField(mod, "Field");

    clsField.def(py::init<std::string const&>(),
            "ident"_a="unknown");

    clsField.def("finalize", &Field::finalize);
    clsField.def("addExt", &Field::addExt);
    clsField.def("getNext", &Field::getNext);
    clsField.def("getPsfs", &Field::getPsfs);

    mod.def("makeit", makeit,
            "fields"_a, "sets"_a);

    return mod.ptr();
}

}}}} // lsst::meas::extensions::fieldex
