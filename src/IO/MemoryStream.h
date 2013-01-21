#pragma once
#ifndef _TEKSTORM_MEMORYSTREAM_H
#define _TEKSTORM_MEMORYSTREAM_H
#include "IStream.h"

namespace Tekstorm
{
	namespace IO
	{
		///
		/// MemoryStream allows the creation of a stream around a pre-allocated memory store.
		/// (For a memory store that is managed, see ManagedMemoryStream)
		///
		class TEKAPI MemoryStream : public IStream
		{
		protected:
			char *_buffer; // underlying memory pointer
			int64 _size; // the underlying size of the stream
			int64 _currentPosition; // the current position in the buffer
			bool _canSeek; // whether or not the stream is seekable
			bool _canRead;
			bool _canWrite;

		public:
			MemoryStream(char *source, int64 size, bool seekable=true, bool readable=true, bool writeable=true);
			~MemoryStream();

			// To be added later:
			// BeginRead, EndRead
			// BeginWrite, EndWrite
			// ReadAsync, WriteAsync
			// CopyToAsync

			///
			/// Opens this memory stream with the given parameters.
			///
			virtual void Open(char *source, int64 size, bool seekable=true, bool readable=true, bool writeable=true);

			///
			/// Returns whether or not the stream is currently open and valid.
			/// \return Returns true if the stream is open, otherwise false.
			///
			virtual bool IsOpen();

			///
			/// Closes the stream. This function closes the stream, but does NOT destroy the memory (as it is
			/// managed by the user). Once the stream is closed it cannot be re-used.
			///
			virtual void Close();

			///
			/// Writes all bytes of this stream to the given stream. This function writes all of the bytes
			/// within this stream to the given stream.
			/// \param destination The stream which should be written to.
			///
			virtual void CopyTo(IStream &destination);

			///
			/// Writes the given number of bytes from this stream to the given stream. This function writes
			/// the given number of bytes from this stream to the given stream.
			/// \param destination The stream which should be written to.
			/// \param count The number of bytes that should be read from this stream.
			///
			virtual void CopyTo(IStream &destination, int64 count);

			///
			/// Flushes this stream. This function flushes all pending data waiting to be written to the stream.
			///
			virtual void Flush();

			///
			/// Reads the given number of bytes from this stream into the given buffer. This function
			/// reads the given number of bytes from this stream into the buffer at a given offset.
			/// \param buffer The buffer in which to read the bytes.
			/// \param offset The offset, in bytes, into the buffer at which the writing will begin.
			/// \param count The number of bytes to be read from the stream.
			/// \return Returns the total number of bytes written.
			///
			virtual int64 Read(char *buffer, int64 offset, int64 count);

			///
			/// Reads a single byte from the stream. This function reads a single byte from the stream,
			/// and returns it as a 32-bit integer.
			/// \return Returns the byte that was read, or -1 if there is nothing to read.
			///
			virtual int32 ReadByte();

			///
			/// Sets the current read position of this stream. This function sets the read position of the stream,
			/// given the number of bytes to offset and the offset origin.
			/// \param offset The number of bytes offset relative to the origin.
			/// \param origin The offset origin (ORIGIN_START,ORIGIN_CURRENT,ORIGIN_END).
			///
			virtual void Seek(int64 offset, int32 origin);

			///
			/// Writes the given bytes to this stream. This functions uses the given buffer and offset to
			/// write the given number of bytes to this stream.
			/// \param buffer The buffer to write from.
			/// \param offset The offset into the buffer to begin writing from.
			/// \param count The number of bytes from buffer to write.
			///
			virtual void Write(const char *buffer, int64 offset, int64 count);

			///
			/// Writes the given byte value to this stream. This function writes the given byte value
			/// to this stream.
			/// \param value The byte value to write to the stream.
			///
			virtual void WriteByte(int32 value);
		};
	}
}


#endif /* _TEKSTORM_ISTREAM_H */
