#define TEKSTORM2D_BUILD
#include "FileStream.h"
#include <iostream>
namespace Tekstorm
{
	namespace IO
	{		
			// To be added later:
			// BeginRead, EndRead
			// BeginWrite, EndWrite
			// ReadAsync, WriteAsync
			// CopyToAsync
			
			FileStream::FileStream(const char *path, int32 mode)
			{
				static const char *modes[] = {"","r","w","rw","a","ra","wa","ra+","b","rb","wb","","ab"};
				_file = fopen(path, modes[mode]);
				if (!_file)
				{
					throw std::runtime_error("An error occurred while opening the file.");
				}
			}

			FileStream::FileStream()
			{
				_file = NULL;
			}

			///
			/// Returns whether or not the stream is currently open and valid.
			/// \return Returns true if the stream is open, otherwise false.
			///
			 bool FileStream::IsOpen()
			{
				if (_file == NULL)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			
			///
			/// Opens the given file path using the given mode.
			/// \param path The file path.
			/// \param mode The mode to open
			/// \return Returns false if it did not open successfully.
			bool FileStream::Open(const char *path, int32 mode)
			{
				static const char *modes[] = {"","r","w","rw","a","ra","wa","ra+","b","rb","wb","","ab"};
				_file = fopen(path, modes[mode]);
				if (!_file)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			
			///
			/// Closes the stream. This function closes the stream. Once a stream is closed it can no longer
			/// be written to. Before the stream is closed, all pending data is flushed and the underlying resource
			/// is destroyed. To recreate the stream, either reinstanciate the resource or check if the specific
			/// implementation has a reopen or open method.
			///
			void FileStream::Close()
			{
				if (!_file)
				{
					throw std::runtime_error("An error occurred while closing the file.");
				}
				
				fclose(_file);
				_file=NULL;
			}
			
			///
			/// Writes all bytes of this stream to the given stream. This function writes all of the bytes
			/// within this stream to the given stream. 
			/// \param destination The stream which should be written to.
			///
			void FileStream::CopyTo(IStream &destination)
			{
				int32 byteValue = 0;
				while ( (byteValue = ReadByte()) != -1 )
				{
					destination.WriteByte(byteValue);
				}
			}
			
			///
			/// Writes the given number of bytes from this stream to the given stream. This function writes
			/// the given number of bytes from this stream to the given stream.
			/// \param destination The stream which should be written to.
			/// \param count The number of bytes that should be read from this stream.
			///
			void FileStream::CopyTo(IStream &destination, int64 count)
			{
				int32 byteValue = 0;
				int64 counter = 0;
				while ( (byteValue = ReadByte()) != -1 && counter < count)
				{
					destination.WriteByte(byteValue);
					counter++;
				}
			}
			
			///
			/// Flushes this stream. This function flushes all pending data waiting to be written to the stream.
			///
			void FileStream::Flush()
			{
				fflush(_file);
			}
			
			///
			/// Reads the given number of bytes from this stream into the given buffer. This function
			/// reads the given number of bytes from this stream into the buffer at a given offset.
			/// \param buffer The buffer in which to read the bytes.
			/// \param offset The offset, in bytes, into the buffer at which the writing will begin.
			/// \param count The number of bytes to be read from the stream.
			/// \return Returns the total number of bytes written.
			///
			int64 FileStream::Read(char *buffer, int64 offset, int64 count)
			{
				size_t size = fread((void *)(buffer + offset), sizeof(char), (size_t)count, _file);
				return (int64)size;
			}
			
			///
			/// Reads a single byte from the stream. This function reads a single byte from the stream,
			/// and returns it as a 32-bit integer.
			/// \return Returns the byte that was read, or -1 if there is nothing to read.
			///
			int32 FileStream::ReadByte()
			{
				int32 res = fgetc(_file);
				if (res == EOF)
				{
					return -1;
				}
				else
				{
					return (int32) res;
				}
			}
			
			///
			/// Sets the current read position of this stream. This function sets the read position of the stream,
			/// given the number of bytes to offset and the offset origin.
			/// \param offset The number of bytes offset relative to the origin.
			/// \param origin The offset origin (ORIGIN_START,ORIGIN_CURRENT,ORIGIN_END).
			///
			void FileStream::Seek(int64 offset, int32 origin)
			{
				static const int location[] = {SEEK_SET, SEEK_CUR, SEEK_END};
				fseek(_file, (size_t)offset, (size_t)location[origin]);
			}
			
			///
			/// Writes the given bytes to this stream. This functions uses the given buffer and offset to
			/// write the given number of bytes to this stream.
			/// \param buffer The buffer to write from.
			/// \param offset The offset into the buffer to begin writing from.
			/// \param count The number of bytes from buffer to write.
			///
			void FileStream::Write(const char *buffer, int64 offset, int64 count)
			{
				fwrite((buffer + offset), sizeof(char), count, _file);
			}
			
			///
			/// Writes the given byte value to this stream. This function writes the given byte value
			/// to this stream.
			/// \param value The byte value to write to the stream.
			///
			void FileStream::WriteByte(int32 value)
			{
				fputc((int)value, _file);
			}
	}
}
