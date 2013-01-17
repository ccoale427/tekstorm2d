#include "Color4.h"

namespace Tekstorm
{
	namespace Math
	{
			///
			/// Creates a new color with all components set to 0.
			///
			Color4::Color4()
			{
				R = G = B = A = (tekreal)0.0;
			}

			///
			/// Creates a new color
			///
			Color4::Color4(const Color4 &other)
			{
				R = other.R;
				G = other.G;
				B = other.B;
				A = other.A;
			}

			///
			/// Creates a new color
			///
			Color4::Color4(tekreal r, tekreal g, tekreal b, tekreal a)
			{
				R = r; G = g; B = b; A = a;
			}

			///
			/// Creates a new color
			///
			Color4::Color4(int r, int g, int b, int a)
			{
				R = (tekreal)(r & 0xFF) / (tekreal)255.0;
				G = (tekreal)(g & 0xFF) / (tekreal)255.0;
				B = (tekreal)(b & 0xFF) / (tekreal)255.0;
				A = (tekreal)(a & 0xFF) / (tekreal)255.0;
			}

			///
			/// Creates a new color from a Vector4. X = red, Y = green, Z = blue, W = alpha
			///
			Color4::Color4(const Vector4& col)
			{
				R = col.X; G = col.Y; B = col.Z; A = col.W;
			}

			///
			/// Creates a new color from an array. [0] = red, [1] = green, [2] = blue, [3] = alpha
			///
			Color4::Color4(const tekreal values[])
			{
				R = values[0]; G = values[1]; B = values[2]; A = values[3];
			}

			///
			/// Gets a Vector3 of each color component.
			///
			Vector3 Color4::GetVector3() const
			{
				return Vector3(R, G, B);
			}

			///
			/// Gets a Vector4 of each color component. W = 1.0
			///
			Vector4 Color4::GetVector4() const
			{
				return Vector4(R, G, B, A);
			}

			///
			/// Adds two colors together
			///
			Color4 Color4::Add(const Color4 &left, const Color4 &right)
			{
				return Color4(left.R + right.R, left.G + right.G, left.B + right.B, left.A + right.A);
			}

			///
			/// Adds two colors together
			///
			void Color4::Add(const Color4 &left, const Color4 &right, Color4 *result)
			{
				result->R = left.R + right.R;
				result->G = left.G + right.G;
				result->B = left.B + right.B;
				result->A = left.A + right.A;
			}

			///
			/// Adds two colors together
			///
			Color4 Color4::Add(const Color4 &left, tekreal right)
			{
				return Color4(left.R + right, left.G + right, left.B + right, left.A + right);
			}

			///
			/// Adds two colors together
			///
			void Color4::Add(const Color4 &left, tekreal right, Color4 *result)
			{
				result->R = left.R + right;
				result->G = left.G + right;
				result->B = left.B + right;
				result->A = left.A + right;
			}

			///
			/// Subtracts two colors
			///
			Color4 Color4::Subtract(const Color4 &left, const Color4 &right)
			{
				return Color4(left.R - right.R, left.G - right.G, left.B - right.B, left.A - right.A);
			}

			///
			/// Subtracts two colors
			///
			void Color4::Subtract(const Color4 &left, const Color4 &right, Color4 *result)
			{
				result->R = left.R - right.R;
				result->G = left.G - right.G;
				result->B = left.B - right.B;
				result->A = left.A - right.A;
			}

			///
			/// Subtracts two colors
			///
			Color4 Color4::Subtract(const Color4 &left, tekreal right)
			{
				return Color4(left.R - right, left.G - right, left.B - right, left.A - right);
			}

			///
			/// Subtracts two colors
			///
			void Color4::Subtract(const Color4 &left, tekreal right, Color4 *result)
			{
				result->R = left.R - right;
				result->G = left.G - right;
				result->B = left.B - right;
				result->A = left.A - right;
			}

			///
			/// Multiplies two colors
			///
			Color4 Color4::Multiply(const Color4 &left, const Color4 &right)
			{
				return Color4(left.R * right.R, left.G * right.G, left.B * right.B, left.A * right.A);
			}

			///
			/// Multiplies two colors
			///
			void Color4::Multiply(const Color4 &left, const Color4 &right, Color4 *result)
			{
				result->R = left.R * right.R;
				result->G = left.G * right.G;
				result->B = left.B * right.B;
				result->A = left.A * right.A;
			}

			///
			/// Multiplies two colors
			///
			Color4 Color4::Multiply(const Color4 &left, tekreal right)
			{
				return Color4(left.R * right, left.G * right, left.B * right, left.A * right);
			}

			///
			/// Multiplies two colors
			///
			void Color4::Multiply(const Color4 &left, tekreal right, Color4 *result)
			{
				result->R = left.R * right;
				result->G = left.G * right;
				result->B = left.B * right;
				result->A = left.A * right;
			}

			///
			/// Divides two colors
			///
			Color4 Color4::Divide(const Color4 &left, const Color4 &right)
			{
				return Color4(left.R / right.R, left.G / right.G, left.B / right.B, left.A / right.A);
			}

			///
			/// Divides two colors
			///
			void Color4::Divide(const Color4 &left, const Color4 &right, Color4 *result)
			{
				result->R = left.R / right.R;
				result->G = left.G / right.G;
				result->B = left.B / right.B;
				result->A = left.A / right.A;
			}

			///
			/// Divides two colors
			///
			Color4 Color4::Divide(const Color4 &left, tekreal right)
			{
				return Color4(left.R / right, left.G / right, left.B / right, left.A / right);
			}

			///
			/// Divides two colors
			///
			void Color4::Divide(const Color4 &left, tekreal right, Color4 *result)
			{
				result->R = left.R / right;
				result->G = left.G / right;
				result->B = left.B / right;
				result->A = left.A / right;
			}


			///
			/// Adds two colors
			///
			Color4 Color4::operator+(const Color4 &right)
			{
				return Color4(R + right.R, G + right.G, B + right.B, A + right.A);
			}

			///
			/// Adds two colors
			///
			Color4 Color4::operator+(tekreal right)
			{
				return Color4(R + right, G + right, B + right, A + right);
			}

			///
			/// Adds two colors
			///
			Color4& Color4::operator+=(const Color4 &right)
			{
				R += right.R;
				G += right.G;
				B += right.B;
				A += right.A;

				return *this;
			}

			///
			/// Adds two colors
			///
			Color4& Color4::operator+=(tekreal right)
			{
				R += right;
				G += right;
				B += right;
				A += right;

				return *this;
			}

			///
			/// Subtracts two colors
			///
			Color4 Color4::operator-(const Color4 &right)
			{
				return Color4(R - right.R, G - right.G, B - right.B, A - right.A);
			}

			///
			/// Subtracts two colors
			///
			Color4 Color4::operator-(tekreal right)
			{
				return Color4(R - right, G - right, B - right, A - right);
			}

			///
			/// Subtracts two colors
			///
			Color4& Color4::operator-=(const Color4 &right)
			{
				R -= right.R;
				G -= right.G;
				B -= right.B;
				A -= right.A;

				return *this;
			}

			///
			/// Subtracts two colors
			///
			Color4& Color4::operator-=(tekreal right)
			{
				R -= right;
				G -= right;
				B -= right;
				A -= right;

				return *this;
			}

			///
			/// Multiplies two colors
			///
			Color4 Color4::operator*(const Color4 &right)
			{
				return Color4(R * right.R, G * right.G, B * right.B, A * right.A);
			}
			
			///
			/// Multiplies two colors
			///
			Color4 Color4::operator*(tekreal right)
			{
				return Color4(R * right, G * right, B * right, A * right);
			}

			///
			/// Multiplies two colors
			///
			Color4& Color4::operator*=(const Color4 &right)
			{
				R *= right.R;
				G *= right.G;
				B *= right.B;
				A *= right.A;

				return *this;
			}

			///
			/// Multiplies two colors
			///
			Color4& Color4::operator*=(tekreal right)
			{
				R *= right;
				G *= right;
				B *= right;
				A *= right;

				return *this;
			}

			///
			/// Divides two colors
			///
			Color4 Color4::operator/(const Color4 &right)
			{
				return Color4(R / right.R, G / right.G, B / right.B, A / right.A);
			}

			///
			/// Divides two colors
			///
			Color4 Color4::operator/(tekreal right)
			{
				return Color4(R / right, G / right, B / right, A / right);
			}

			///
			/// Divides two colors
			///
			Color4& Color4::operator/=(const Color4 &right)
			{
				R /= right.R;
				G /= right.G;
				B /= right.B;
				A /= right.A;
				
				return *this;
			}

			///
			/// Divides two colors
			///
			Color4& Color4::operator/=(tekreal right)
			{
				R /= right;
				G /= right;
				B /= right;
				A /= right;

				return *this;
			}

			// -- standard colors --
			const Color4 Color4::AliceBlue = Color4(240, 248, 255);
			const Color4 Color4::AntiqueWhite = Color4(250, 235, 215);
			const Color4 Color4::Aqua = Color4(0, 255, 255);
			const Color4 Color4::Aquamarine = Color4(127, 255, 212);
			const Color4 Color4::Azure = Color4(240, 255, 255);
			const Color4 Color4::Beige = Color4(245, 245, 220);
			const Color4 Color4::Bisque = Color4(225, 228, 196);
			const Color4 Color4::Black = Color4(0, 0, 0);
			const Color4 Color4::BlanchedAlmond = Color4(225, 235, 205);
			const Color4 Color4::Blue = Color4(0, 0, 255);
			const Color4 Color4::BlueViolet = Color4(138, 226, 255);
			const Color4 Color4::Brown = Color4(165, 42, 255);
			const Color4 Color4::BurlyWood = Color4(222, 184, 135);
			const Color4 Color4::CadetBlue = Color4(95, 158, 160);
			const Color4 Color4::Chartreuse = Color4(127, 255, 0);
			const Color4 Color4::Chocolate = Color4(210, 105, 30);
			const Color4 Color4::Coral = Color4(255, 127, 80);
			const Color4 Color4::CornflowerBlue = Color4(100, 149, 237);
			const Color4 Color4::Cornsilk = Color4(255, 248, 220);
			const Color4 Color4::Crimson = Color4(220, 20, 60);
			const Color4 Color4::Cyan = Color4(0, 255, 255);
			const Color4 Color4::DarkBlue = Color4(0, 0, 139);
			const Color4 Color4::DarkCyan = Color4(0, 139, 139);
			const Color4 Color4::DarkGoldenrod = Color4(184, 134, 11);
			const Color4 Color4::DarkGray = Color4(169, 169, 169);
			const Color4 Color4::DarkGreen = Color4(0, 100, 0);
			const Color4 Color4::DarkKhaki = Color4(189, 183, 107);
			const Color4 Color4::DarkMagenta = Color4(139, 0, 139);
			const Color4 Color4::DarkOliveGreen = Color4(85, 107, 47);
			const Color4 Color4::DarkOrange = Color4(255, 140, 0);
			const Color4 Color4::DarkOrchid = Color4(153, 50, 204);
			const Color4 Color4::DarkRed = Color4(139, 0, 0);
			const Color4 Color4::DarkSalmon = Color4(233, 150, 122);
			const Color4 Color4::DarkSeaGreen = Color4(143, 188, 139);
			const Color4 Color4::DarkSlateBlue = Color4(72, 61, 139);
			const Color4 Color4::DarkSlateGray = Color4(47, 79, 79);
			const Color4 Color4::DarkTurquoise = Color4(0, 206, 209);
			const Color4 Color4::DarkViolet = Color4(148, 0, 211);
			const Color4 Color4::DeepPink = Color4(255, 20, 147);
			const Color4 Color4::DeepSkyBlue = Color4(0, 191, 255);
			const Color4 Color4::DimGray = Color4(105, 105, 105);
			const Color4 Color4::DodgerBlue = Color4(30, 144, 255);
			const Color4 Color4::Firebrick = Color4(178, 34, 34);
			const Color4 Color4::FloralWhite = Color4(255, 250, 240);
			const Color4 Color4::ForestGreen = Color4(34, 139, 34);
			const Color4 Color4::Fuchsia = Color4(255, 0, 255);
			const Color4 Color4::Grainsboro = Color4(220, 220, 220);
			const Color4 Color4::GhostWhite = Color4(248, 248, 255);
			const Color4 Color4::Gold = Color4(255, 215, 0);
			const Color4 Color4::Goldenrod = Color4(218, 165, 32);
			const Color4 Color4::Gray = Color4(128, 128, 128);
			const Color4 Color4::Green = Color4(0, 128, 0);
			const Color4 Color4::GreenYellow = Color4(173, 255, 47);
			const Color4 Color4::Honeydew = Color4(240, 255, 240);
			const Color4 Color4::HotPink = Color4(255, 105, 180);
			const Color4 Color4::IndianRed = Color4(205, 92, 92);
			const Color4 Color4::Indigo = Color4(75, 0, 130);
			const Color4 Color4::Ivory = Color4(255, 255, 240);
			const Color4 Color4::Khaki = Color4(240, 230, 140);
			const Color4 Color4::Lavender = Color4(230, 230, 250);
			const Color4 Color4::LavenderBlush = Color4(255, 240, 245);
			const Color4 Color4::LawnGreen = Color4(124, 252, 0);
			const Color4 Color4::LemonChiffon = Color4(255, 250, 205);
			const Color4 Color4::LightBlue = Color4(173, 216, 230);
			const Color4 Color4::LightCoral = Color4(240, 128, 128);
			const Color4 Color4::LightCyan = Color4(224, 255, 255);
			const Color4 Color4::LightGoldenrodYellow = Color4(250, 250, 210);
			const Color4 Color4::LightGray = Color4(211, 211, 211);
			const Color4 Color4::LightGreen = Color4(144, 238, 144);
			const Color4 Color4::LightPink = Color4(255, 182, 193);
			const Color4 Color4::LightSalmon = Color4(255, 160, 122);
			const Color4 Color4::LightSeaGreen = Color4(32, 178, 170);
			const Color4 Color4::LightSkyBlue = Color4(135, 206, 250);
			const Color4 Color4::LightSlateGray = Color4(119, 136, 153);
			const Color4 Color4::LightSteelBlue = Color4(176, 196, 222);
			const Color4 Color4::LightYellow = Color4(255, 255, 224);
			const Color4 Color4::Lime = Color4(0, 255, 0);
			const Color4 Color4::LimeGreen = Color4(50, 205, 50);
			const Color4 Color4::Linen = Color4(250, 240, 230);
			const Color4 Color4::Magenta = Color4(255, 0, 255);
			const Color4 Color4::Maroon = Color4(128, 0, 0);
			const Color4 Color4::MediumAquamarine = Color4(102, 105, 170);
			const Color4 Color4::MediumBlue = Color4(0, 0, 205);
			const Color4 Color4::MediumOrchid = Color4(186, 85, 211);
			const Color4 Color4::MediumPurple = Color4(147, 112, 219);
			const Color4 Color4::MediaSeaGreen = Color4(60, 179, 113);
			const Color4 Color4::MediumSlateBlue = Color4(123, 104, 238);
			const Color4 Color4::MediumSpringGreen = Color4(0, 250, 154);
			const Color4 Color4::MediumTurquoise = Color4(72, 209, 204);
			const Color4 Color4::MediumVioletRed = Color4(199, 21, 133);
			const Color4 Color4::MidnightBlue = Color4(25, 25, 112);
			const Color4 Color4::MintCream = Color4(245, 255, 250);
			const Color4 Color4::MistyRose = Color4(255, 228, 225);
			const Color4 Color4::Moccasin = Color4(255, 228, 181);
			const Color4 Color4::NavajoWhite = Color4(255, 222, 173);
			const Color4 Color4::Navy = Color4(0, 0, 128);
			const Color4 Color4::OldLace = Color4(253, 245, 230);
			const Color4 Color4::Olive = Color4(128, 128, 0);
			const Color4 Color4::OliveDrab = Color4(107, 142, 35);
			const Color4 Color4::Orange = Color4(255, 165, 0);
			const Color4 Color4::OrangeRed = Color4(255, 69, 0);
			const Color4 Color4::Orchid = Color4(218, 112, 214);
			const Color4 Color4::PaleGoldenrod = Color4(238, 232, 170);
			const Color4 Color4::PaleGreen = Color4(152, 251, 152);
			const Color4 Color4::PaleTurquoise = Color4(175, 238, 238);
			const Color4 Color4::PaleVioletRed = Color4(219, 112, 147);
			const Color4 Color4::PapayaWhip = Color4(255, 239, 213);
			const Color4 Color4::PeachPuff = Color4(255, 218, 185);
			const Color4 Color4::Peru = Color4(205, 133, 63);
			const Color4 Color4::Pink = Color4(255, 192, 203);
			const Color4 Color4::Plum = Color4(221, 160, 221);
			const Color4 Color4::PowderBlue = Color4(176, 224, 230);
			const Color4 Color4::Purple = Color4(128, 0, 128);
			const Color4 Color4::Red = Color4(255, 0, 0);
			const Color4 Color4::RosyBrown = Color4(188, 143, 143);
			const Color4 Color4::RoyalBlue = Color4(65, 105, 225);
			const Color4 Color4::SaddleBrown = Color4(139, 69, 19);
			const Color4 Color4::Salmon = Color4(250, 128, 114);
			const Color4 Color4::SandyBrown = Color4(244, 164, 96);
			const Color4 Color4::SeaGreen = Color4(46, 139, 87);
			const Color4 Color4::SeaShell = Color4(255, 245, 238);
			const Color4 Color4::Sienna = Color4(160, 82, 45);
			const Color4 Color4::Silver = Color4(192, 192, 192);
			const Color4 Color4::SkyBlue = Color4(135, 206, 235);
			const Color4 Color4::SlateBlue = Color4(106, 90, 205);
			const Color4 Color4::SlateGray = Color4(112, 128, 144);
			const Color4 Color4::Snow = Color4(255, 250, 250);
			const Color4 Color4::SpringGreen = Color4(0, 255, 127);
			const Color4 Color4::SteelBlue = Color4(70, 130, 180);
			const Color4 Color4::Tan = Color4(210, 180, 140);
			const Color4 Color4::Teal = Color4(0, 128, 128);
			const Color4 Color4::Thistle = Color4(216, 191, 216);
			const Color4 Color4::Tomato = Color4(255, 99, 71);
			const Color4 Color4::TransparentBlack = Color4(0, 0, 0, 0);
			const Color4 Color4::TransparentWhite = Color4(255, 255, 255, 0);
			const Color4 Color4::Turquoise = Color4(64, 224, 208);
			const Color4 Color4::Violet = Color4(238, 130, 238);
			const Color4 Color4::Wheat = Color4(245, 222, 179);
			const Color4 Color4::White = Color4(255, 255, 255);
			const Color4 Color4::WhiteSmoke = Color4(245, 245, 245);
			const Color4 Color4::Yellow = Color4(255, 255, 0);
			const Color4 Color4::YellowGreen = Color4(154, 205, 50);
	}
}