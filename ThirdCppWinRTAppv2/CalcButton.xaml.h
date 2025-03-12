#pragma once

#include "CalcButton.g.h"

namespace winrt::ThirdCppWinRTAppv2::implementation
{
	struct CalcButton : CalcButtonT<CalcButton>
	{
		CalcButton();

		static void OnPropertyChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);
		
		winrt::hstring TopText();
		void TopText(hstring const& value);

		winrt::hstring BottomText();
		void BottomText(hstring const& value);

		winrt::Windows::UI::Text::FontWeight TopTextFontWeight();
		void TopTextFontWeight(winrt::Windows::UI::Text::FontWeight const& value);

		winrt::Windows::UI::Text::FontWeight BottomTextFontWeight();
		void BottomTextFontWeight(winrt::Windows::UI::Text::FontWeight const& value);

		static winrt::Microsoft::UI::Xaml::DependencyProperty TopTextProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty BottomTextProperty();

		static winrt::Microsoft::UI::Xaml::DependencyProperty TopTextFontWeightProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty BottomTextFontWeightProperty();

		winrt::Microsoft::UI::Xaml::Media::Brush ButtonBackground();
		void ButtonBackground(winrt::Microsoft::UI::Xaml::Media::Brush const& value);

		winrt::Microsoft::UI::Xaml::Media::Brush TopTextForeground();
		void TopTextForeground(winrt::Microsoft::UI::Xaml::Media::Brush const& value);

		winrt::Microsoft::UI::Xaml::Media::Brush BottomTextForeground();
		void BottomTextForeground(winrt::Microsoft::UI::Xaml::Media::Brush const& value);

		static winrt::Microsoft::UI::Xaml::DependencyProperty ButtonBackgroundProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty TopTextForegroundProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty BottomTextForegroundProperty();

		winrt::event_token CalcButtonClicked(winrt::Windows::Foundation::TypedEventHandler<ThirdCppWinRTAppv2::CalcButton, winrt::Microsoft::UI::Xaml::RoutedEventArgs> const& handler);
		void CalcButtonClicked(winrt::event_token const& token) noexcept;
		void myCalcButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& args);
	private:
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextProperty;
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextProperty;

		static winrt::Microsoft::UI::Xaml::DependencyProperty m_buttonBackgroundProperty;
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextForegroundProperty;
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextForegroundProperty;

		static bool m_isFirstTime;
		static winrt::Microsoft::UI::Xaml::Media::Brush m_buttonBrush;
		static winrt::Microsoft::UI::Xaml::Media::Brush m_topTextBrush;
		static winrt::Microsoft::UI::Xaml::Media::Brush m_bottomTextBrush;
		static winrt::Windows::UI::Text::FontWeight m_boldFontWeight;
		static winrt::Windows::UI::Text::FontWeight m_normalFontWeight;

		//static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextFontWeight;
		//static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextFontWeight;

		static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextFontWeightProperty;
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextFontWeightProperty;

		void InitializeDefaultBrushes();

		winrt::Microsoft::UI::Xaml::Controls::TextBlock m_topTextBlock{ nullptr };
		winrt::Microsoft::UI::Xaml::Controls::TextBlock m_bottomTextBlock{ nullptr };

		winrt::event<winrt::Windows::Foundation::TypedEventHandler<ThirdCppWinRTAppv2::CalcButton, winrt::Microsoft::UI::Xaml::RoutedEventArgs>> m_clickToken;

		// static winrt::Windows::UI::Color StringToColor(winrt::hstring const&);

		static void OnButtonBackgroundChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);
		static void OnTextForegroundChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);
	};
}

namespace winrt::ThirdCppWinRTAppv2::factory_implementation
{
	struct CalcButton : CalcButtonT<CalcButton, implementation::CalcButton>
	{
	};
}
