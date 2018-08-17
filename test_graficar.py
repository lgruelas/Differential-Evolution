import graficar

def test_c_output():
    assert(type(graficar.run_cpp())==list)

def test_individual_c_output():
    a = graficar.run_cpp()
    assert(type(a[0])==type(a[1])==type(a[2])==type(a[3])==float)
