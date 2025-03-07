#pragma once

#include "CalcButtom.g.h"

namespace winrt::ThirdCppWinRTAppv2::implementation
{
    struct CalcButtom : CalcButtomT<CalcButtom>
    {
        CalcButtom()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::ThirdCppWinRTAppv2::factory_implementation
{
    struct CalcButtom : CalcButtomT<CalcButtom, implementation::CalcButtom>
    {
    };
}
