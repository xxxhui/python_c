//https://daobook.github.io/pybind11/basics.html
//https://github.com/pybind/pybind11/blob/master/tests/test_class.py


#include <pybind11/pybind11.h>
// #include <pybind11/functional.h>
// #include <pybind11/numpy.h>
// #define x86_64

namespace py = pybind11;

void test_invoke_py() {
    py::module_ os = py::module_::import("os");
    py::module_ path = py::module_::import("os.path");  // like 'import os.path as path'

    py::str curdir_abs = path.attr("abspath")(path.attr("curdir"));
    py::print(py::str("Current directory: ") + curdir_abs);
    py::dict environ = os.attr("environ");
    py::print(environ["HOME"]);

}

int main(int argc, char* argv[]) {
    test_invoke_py();
    return 0;
}


int add(int i, int j) {
    return i + j;
}

struct Pet {
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

    std::string name;
};

typedef struct {
int x;
int y;
} Point;

static Point _point;

Point *getPoint() {
_point.x = 10;
_point.y = 11;
return &_point;
}

int func_arg(const std::function<int(int)> &f) {
    return f(10);
}

std::function<int(int)> func_ret(const std::function<int(int)> &f) {
    return [f](int i) {
        return f(i) + 1;
    };
}

py::cpp_function func_cpp() {
    return py::cpp_function([](int i) { return i+1; },
       py::arg("number"));
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
    m.def("test_invoke_py", &test_invoke_py, "test_invoke_py");

    m.def("func_arg", &func_arg);
    m.def("func_ret", &func_ret);
    m.def("func_cpp", &func_cpp);

     py::class_<Point>(m, "Point")
        .def(py::init<>())
        .def_readwrite("x", &Point::x)
        .def_readwrite("y", &Point::y);

    m.def("getPoint", &getPoint, py::return_value_policy::automatic_reference);

    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        .def("__repr__",
        [](const Pet &a) {
            return "<example.Pet named '" + a.name + "'>";
        });
}





