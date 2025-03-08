#include "pch.h"
#include "BgLabelControl.h"
#if __has_include("BgLabelControl.g.cpp")
#include "BgLabelControl.g.cpp"
#endif

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ThirdCppWinRTAppv2::implementation
{
	Microsoft::UI::Xaml::DependencyProperty BgLabelControl::m_LabelProperty =
		Microsoft::UI::Xaml::DependencyProperty::Register(
			L"Label",
			winrt::xaml_typename<winrt::hstring>(),
			winrt::xaml_typename<winrt::ThirdCppWinRTAppv2::BgLabelControl>(),
			Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L"default label"), Microsoft::UI::Xaml::PropertyChangedCallback{ &BgLabelControl::OnLabelChanged } }
		);

	void BgLabelControl::OnLabelChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&)
	{
		if (ThirdCppWinRTAppv2::BgLabelControl theControl{ d.try_as<ThirdCppWinRTAppv2::BgLabelControl>() })
		{
			// Call members of the projected type via theControl

			ThirdCppWinRTAppv2::implementation::BgLabelControl* ptr{ winrt::get_self<ThirdCppWinRTAppv2::implementation::BgLabelControl>(theControl) };
		}
	}
}
