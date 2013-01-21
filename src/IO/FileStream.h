#pragma once
#ifndef _TEKSTORM_FILESTREAM_H
#define _TEKSTORM_FILESTREAM_H
#include "IStream.h"
#include <cstdio>

namespace Tekstorm
{
	namespace IO
	{	
		const int32 MODE_READ = 0x01;
		const int32 MODE_WRITE = 0x02;
		const int32 MODE_APPEND = 0x04;
		const int32 MODE_BINARY = 0x08;
		
		///
		/// Standard interface for all streams. This is the standard interface which should always be used
		/// to implement any kind of streaming data (networking, files, memory, etc.) that is used within
		/// this engine. The stream index and offset values are of type int64_t.
		///
		class TEKAPI FileStream : public IStream
		{
		protected:
			FILE *_file; // the underlying file system file object
			
		public:
			// To be added later:
			// BeginRead, EndRead
			// BeginWrite, EndWrite
			// ReadAsync, WriteAsync
			// CopyToAsync
			
			FileStream(const char *path, int32 mode);

			FileStream();

			///
			/// Returns whether or not the stream is currently open and valid.
			/// \return Returns true if the stream is open, otherwise false.
			///
			virtual bool IsOpen();
			///
			/// Opens the given file path using the given mode.
			/// \param path The file path.
			/// \param mode The mode to open
			/// \return Returns false if it did not open successfully.
			virtual bool Open(const char *path, int32 mode);
			
			///
			/// Closes the stream. This function closes the stream. Once a stream is closed it can no longer
			/// be written to. Before the stream is closed, all pending data is flushed and the underlying resource
			/// is destroyed. To recreate the stream, either reinstanciate the resource or check if the specific
			/// implementation has a reopen or open method.
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