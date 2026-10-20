/* Beta 3 export variant; keep the original beta 2 implementation intact. */
#include "d3d12shim.c"

HRESULT WINAPI shimD3D12GetInterface(REFCLSID clsid, REFIID iid, void **out)
{
    typedef HRESULT (WINAPI *get_interface_fn)(REFCLSID, REFIID, void **);
    get_interface_fn fn = (get_interface_fn)real_fn("D3D12GetInterface");
    return fn ? fn(clsid, iid, out) : E_NOINTERFACE;
}
