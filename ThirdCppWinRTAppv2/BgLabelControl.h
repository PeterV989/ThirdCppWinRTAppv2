#pragma once

#include "BgLabelControl.g.h"

namespace winrt::ThirdCppWinRTAppv2::implementation
{
    struct BgLabelControl : BgLabelControlT<BgLabelControl>
    {
        BgLabelControl() { DefaultStyleKey(winrt::box_value(L"ThirdCppWinRTAppv2.BgLabelControl")); }

		winrt::hstring Label()
		{
			return winrt::unbox_value<winrt::hstring>(GetValue(m_LabelProperty));
		}

		void Label(winrt::hstring const& value)
		{
			SetValue(m_LabelProperty, winrt::box_value(value));
		}

		static Microsoft::UI::Xaml::DependencyProperty LabelProperty() { return m_LabelProperty; }

		static void OnLabelChanged(Microsoft::UI::Xaml::DependencyObject const&, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

	private:
		static Microsoft::UI::Xaml::DependencyProperty m_LabelProperty;
    };
}

namespace winrt::ThirdCppWinRTAppv2::factory_implementation
{
    struct BgLabelControl : BgLabelControlT<BgLabelControl, implementation::BgLabelControl>
    {
    };
}
