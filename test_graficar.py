import graficar

def test_c_output():
    assert(type(graficar.run_cpp())==list)
