#define TEKSTORM2D_BUILD
#include "MemoryStream.h"

namespace Tekstorm
{
	namespace IO
	{

			MemoryStream::MemoryStream(char *source, int64 size, bool seekable, bool readable, bool writeable)
			{
                if (_buffer == NULL || size <= 0)
                {
                    throw std::runtime_error("Invalid source buffer data!");
                }

			    _buffer = source;
			    _size = size;
                _canSeek = seekable;
                _canRead = readable;
                _canWrite = writeable;
                _currentPosition = 0;
			}

			MemoryStream::~MemoryStream()
			{
			    // do nothing since this stream is unmanaged
			}

			// To be added later:
			// BeginRead, EndRead
			// BeginWrite, EndWrite
			// ReadAsync, WriteAsync
			// CopyToAsync

			///
			/// Opens this memory stream with the given parameters.
			///
			void MemoryStream::Open(char *source, int64 size, bool seekable, bool readable, bool writeable)
			{
                if (_buffer == NULL || size <= 0)
                {
                    throw std::runtime_error("Invalid source buffer data!");
                }

			    _buffer = source;
			    _size = size;
                _canSeek = seekable;
                _canRead = readable;
                _canWrite = writeable;
                _currentPosition = 0;
			}

			///
			/// Returns whether or not the stream is currently open and valid.
			/// \return Returns true if the stream is open, otherwise false.
			///
			bool MemoryStream::IsOpen()
			{
			    if (_buffer == NULL)
			    {
			        return false;
			    }
			    else
			    {
			        return true;
			    }

			}

			///
			/// Closes the stream. This function closes the stream, but does NOT destroy the memory (as it is
			/// managed by the user). Once the stream is closed it cannot be re-used.
			///
			void MemoryStream::Close()
			{
			    _buffer = NULL;
			    _size = 0;
			    _canSeek = _canRead = _canWrite = false;
			    _currentPosition = 0;
			}

			///
			/// Writes all bytes of this stream to the given stream. This function writes all of the bytes
			/// within this stream to the given stream.
			/// \param destination The stream which should be written to.
			///
			void MemoryStream::CopyTo(IStream &destination)
			{
			    if (! _canRead)
			    {
			        return;
			    }

			    int32 value = 0;
			    while ( (value = ReadByte()) != -1)
			    {
			        destination.WriteByte(value);
			    }
			}

			///
			/// Writes the given number of bytes from this stream to the given stream. This function writes
			/// the given number of bytes from this stream to the given stream.
			/// \param destination The stream which should be written to.
			/// \param count The number of bytes that should be read from this stream.
			///
			void MemoryStream::CopyTo(IStream &destination, int64 count)
			{
			    // unable to read from stream
			    if (! _canRead)
			    {
			        return;
			    }

                int32 value = 0;
                int64 counter = 0;
                while ( (value = ReadByte()) != -1 && counter < count)
                {
                    destination.WriteByte(value);
                    counter++;
                }
            }

			///
			/// Flushes this stream. This function flushes all pending data waiting to be written to the stream.
			///
			void MemoryStream::Flush()
			{
			    // nothing to do here, the data is not queued
			}

			///
			/// Reads the given number of bytes from this stream into the given buffer. This function
			/// reads the given number of bytes from this stream into the buffer at a given offset.
			/// \param buffer The buffer in which to read the bytes.
			/// \param offset The offset, in bytes, into the buffer at which the writing will begin.
			/// \param count The number of bytes to be read from the stream.
			/// \return Returns the total number of bytes written.
			///
			int64 MemoryStream::Read(char *buffer, int64 offset, int64 count)
			{
			    // if the stream is not readable, return 0 bytes
			    if (! _canRead)
			    {
			        return 0;
			    }

			    if (_currentPosition >= _size)
			    {
			        return -1;
			    }

                // First we need to determine how many bytes can be read from our buffer:
                int64 remain = _size - _currentPosition; // number of bytes remaining
                // can we read the full number of "count" bytes?
                if (remain >= count)
                {
                    memcpy(buffer+offset, _buffer, sizeof(char)*count);
                    _currentPosition += count;
                    return count;
                }
                else
                {
                    // there is no enough to read the full count, so how much can we read? "remain"
                    memcpy(buffer+offset, _buffer, sizeof(char)*remain);
                    _currentPosition += remain;
                    return remain;
                }
			}

			///
			/// Reads a single byte from the stream. This function reads a single byte from the stream,
			/// and returns it as a 32-bit integer.
			/// \return Returns the byte that was read, or -1 if there is nothing to read.
			///
			int32 MemoryStream::ReadByte()
			{
                if (! _canRead)
                {
                    return 0;
                }

			    if (_currentPosition < _size)
			    {
			        return _buffer[_currentPosition++];
			    }
			    else
			    {
                    return -1;
                }
			}

			///
			/// Sets the current read position of this stream. This function sets the read position of the stream,
			/// given the number of bytes to offset and the offset origin.
			/// \param offset The number of bytes offset relative to the origin.
			/// \param origin The offset origin (ORIGIN_START,ORIGIN_CURRENT,ORIGIN_END).
			///
			void MemoryStream::Seek(int64 offset, int32 origin)
			{
			    // cannot seek
                if (! _canSeek)
                {
                    return;
                }

                // set the current position
                if (origin == ORIGIN_START)
                {
                    if (offset < _size)
                    {
                        _currentPosition = offset;
                    }
                }
                else if (origin == ORIGIN_CURRENT)
                {
                    if (_currentPosition + offset < _size)
                    {
                        _currentPosition = _currentPosition + offset;
                    }
                }
                else if (origin == ORIGIN_END)
                {
                    if (_size - offset > 0)
                    {
                        _currentPosition = _size - offset;
                    }
                }
			}

			///
			/// Writes the given bytes to this stream. This functions uses the given buffer and offset to
			/// write the given number of bytes to this stream.
			/// \param buffer The buffer to write from.
			/// \param offset The offset into the buffer to begin writing from.
			/// \param count The number of bytes from buffer to write.
			///
			void MemoryStream::Write(const char *buffer, int64 offset, int64 count)
			{
                // unwriteable
                if (! _canWrite)
                {
                    return;
                }

                if (_currentPosition >= _size)
                {

                    return;
                }

                // determine the total number of bytes that can be written
                int64 remain = _size - _currentPosition;

                int64 amount = (count < remain ? count : remain);

                memcpy(_buffer + _currentPosition, buffer + offset, (size_t)count * sizeof(char));
			}

			///
			/// Writes the given byte value to this stream. This function writes the given byte value
			/// to this stream.
			/// \param value The byte value to write to the stream.
			///
			void MemoryStream::WriteByte(int32 value)
			{
                if (!_canWrite)
                {
                    return;
                }

                if (_currentPosition+1 >= _size)
                {
                    return;
                }

                _buffer[_currentPosition++] = (char)value;
			}

	}
}
