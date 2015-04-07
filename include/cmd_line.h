#define MAX_PATH_LENGTH 1024
#define DO_SCREEN 1
#define DO_FILTER 2
#define DO_INDEX 3

typedef enum
{
    UNSPECIFIED_FORMAT   = 0,
    FASTA                = 1,
    FASTQ                = 2,
    CTX                  = 3,
    ROCHE                = 4,
    HASH                 = 5,
    CSFASTA              = 6,
    KMERS                = 7,
    FILE_FORMAT_LAST     = 8,
} FileFormat ;

typedef struct {
    int bucket_bits;
    int bucket_size;
    int run_type;
    int kmer_size;
    FileFormat format;
    int quality_score_offset;
    int quality_score_threshold;
    int max_read_length;
    int kmer_threshold;
    boolean keep_contaminated_reads;
    boolean write_progress_file;
    int progress_delay;
    char* input_filename_one;
    char* input_filename_two;
    char* file_of_files;
    char* progress_dir;
    char* contaminants;
    char* contaminant_dir;
    char* output_prefix;
    char* removed_prefix;
    double subsample_ratio;
    int filter_unique_threshold;
    int filter_any_threshold;
} CmdLine;

void initialise_cmdline(CmdLine* c);
void parse_command_line(int argc, char* argv[], CmdLine* c);