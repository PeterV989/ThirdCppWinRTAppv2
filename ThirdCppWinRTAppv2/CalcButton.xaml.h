#pragma once

#include "CalcButton.g.h"

namespace winrt::ThirdCppWinRTAppv2::implementation
{
	struct CalcButton : CalcButtonT<CalcButton, Microsoft::UI::Xaml::Controls::UserControl, Microsoft::UI::Xaml::Data::INotifyPropertyChanged>
	{
		CalcButton();

		// Getters & Setters

		winrt::hstring TopText();
		void TopText(hstring const& value);

		winrt::hstring BottomText();
		void BottomText(hstring const& value);

		winrt::Windows::UI::Text::FontWeight TopTextFontWeight();
		void TopTextFontWeight(winrt::Windows::UI::Text::FontWeight const& value);

		winrt::Windows::UI::Text::FontWeight BottomTextFontWeight();
		void BottomTextFontWeight(winrt::Windows::UI::Text::FontWeight const& value);

		winrt::Microsoft::UI::Xaml::Media::Brush ButtonBackground();
		void ButtonBackground(winrt::Microsoft::UI::Xaml::Media::Brush const& value);

		winrt::Microsoft::UI::Xaml::Media::Brush TopTextForeground();
		void TopTextForeground(winrt::Microsoft::UI::Xaml::Media::Brush const& value);

		winrt::Microsoft::UI::Xaml::Media::Brush BottomTextForeground();
		void BottomTextForeground(winrt::Microsoft::UI::Xaml::Media::Brush const& value);

		// Dependency Property
		static winrt::Microsoft::UI::Xaml::DependencyProperty ButtonBackgroundProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty TopTextForegroundProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty BottomTextForegroundProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty TopTextProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty BottomTextProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty TopTextFontWeightProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty BottomTextFontWeightProperty();

		winrt::event_token CalcButtonClicked(winrt::Windows::Foundation::TypedEventHandler<ThirdCppWinRTAppv2::CalcButton, winrt::Microsoft::UI::Xaml::RoutedEventArgs> const& handler);
		void CalcButtonClicked(winrt::event_token const& token) noexcept;
		void myCalcButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& args);
		winrt::event<winrt::Windows::Foundation::TypedEventHandler<ThirdCppWinRTAppv2::CalcButton, winrt::Microsoft::UI::Xaml::RoutedEventArgs>> m_clickToken;

		winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
		void PropertyChanged(winrt::event_token const& token) noexcept;
	private:
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextProperty;
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextProperty;

		static winrt::Microsoft::UI::Xaml::DependencyProperty m_buttonBackgroundProperty;
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextForegroundProperty;
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextForegroundProperty;

		static bool m_isFirstTime;
		static winrt::Microsoft::UI::Xaml::Media::Brush m_buttonBackgroundDefaultBrush;
		static winrt::Microsoft::UI::Xaml::Media::Brush m_topTextForegroundDefaultBrush;
		static winrt::Microsoft::UI::Xaml::Media::Brush m_bottomTextForegroundDefaultBrush;
		static winrt::Windows::UI::Text::FontWeight m_boldFontWeight;
		static winrt::Windows::UI::Text::FontWeight m_normalFontWeight;
		winrt::Microsoft::UI::Xaml::Media::Brush m_topTextForegroundBrush{ nullptr };
		winrt::Microsoft::UI::Xaml::Media::Brush m_bottomTextForegroundBrush{ nullptr };
		winrt::Microsoft::UI::Xaml::Media::Brush m_buttonBackgroundBrush{ nullptr };

		static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextFontWeightProperty;
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextFontWeightProperty;

		void InitializeDefaultBrushes();

		winrt::Microsoft::UI::Xaml::Controls::TextBlock m_topTextBlock{ nullptr };
		winrt::Microsoft::UI::Xaml::Controls::TextBlock m_bottomTextBlock{ nullptr };

		static void OnButtonBackgroundChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);
		static void OnTextForegroundChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);

		winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
		void RaisePropertyChanged(winrt::hstring const& propertyName);
		static void OnPropertyChanged(winrt::Microsoft::UI::Xaml::DependencyObject const& d, winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);
	};
}

namespace winrt::ThirdCppWinRTAppv2::factory_implementation
{
	struct CalcButton : CalcButtonT<CalcButton, implementation::CalcButton>
	{
	};
}
