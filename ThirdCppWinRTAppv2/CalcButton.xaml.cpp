#include "pch.h"
#include "CalcButton.xaml.h"
#if __has_include("CalcButton.g.cpp")
#include "CalcButton.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ThirdCppWinRTAppv2::implementation
{
	void CalcButton::myCalcButton_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
	{
	}

	hstring CalcButton::TopText()
	{
		return winrt::unbox_value<hstring>(GetValue(m_topTextProperty));
	}

	void CalcButton::TopText(hstring const& value)
	{
		SetValue(m_topTextProperty, winrt::box_value(value));
	}

	hstring CalcButton::BottomText()
	{
		return winrt::unbox_value<hstring>(GetValue(m_bottomTextProperty));
	}

	void CalcButton::BottomText(hstring const& value)
	{
		SetValue(m_bottomTextProperty, winrt::box_value(value));
	}


	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::TopTextProperty()
	{
		return m_topTextProperty;
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::BottomTextProperty()
	{
		return m_bottomTextProperty;
	}

	void CalcButton::OnPropertyChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&)
	{
		if (auto button = d.try_as<winrt::ThirdCppWinRTAppv2::CalcButton>())
		{
		}
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topTextProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"TopText",
			winrt::xaml_typename<winrt::hstring>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ box_value(L"Default Top"), Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnPropertyChanged } });

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomTextProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"BottomText",
			winrt::xaml_typename<winrt::hstring>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ box_value(L"Default Bottom"), Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnPropertyChanged } });
}
