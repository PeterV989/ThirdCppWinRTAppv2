#include "pch.h"
#include "CalcButtom.xaml.h"
#if __has_include("CalcButtom.g.cpp")
#include "CalcButtom.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ThirdCppWinRTAppv2::implementation
{
    int32_t CalcButtom::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void CalcButtom::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void CalcButtom::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
